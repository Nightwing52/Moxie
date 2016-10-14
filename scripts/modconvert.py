#!/usr/bin/python

# Converts other 3D formats into a Moxie file
# Requires PyAssimp

import argparse
import itertools
import struct
from pyassimp import *

parser = argparse.ArgumentParser()
parser.add_argument("filename", help="filename of the Collada model")
parser.add_argument("result", help="resulting filename of the Moxie file")
parser.add_argument("-v", "--verbose", help="verbose output", action="store_true")
args = parser.parse_args()

if args.verbose:
    print("Converting %s..." % (args.filename))

scene = load(args.filename)
mesh = scene.meshes[0]

verts = list(itertools.chain.from_iterable(mesh.vertices))
norms = list(itertools.chain.from_iterable(mesh.normals))
crds = list(itertools.chain.from_iterable(mesh.texturecoords))

numVerts = len(verts)
numNorms = len(norms)
numCrds = len(crds)

if args.verbose:
    print("Found", numVerts, "vertices")
    print("Found", numNorms, "normals")
    print("Found", numCrds, "texture coordinates")


f = open(args.result, "wb")
f.write(bytes([0xFE, 0x4D, 0x4F, 0x58]))
f.write(bytes([0x4D, 0xE5]))
f.write(struct.pack('>H', numVerts))
f.write(struct.pack('%sf' % numVerts, *verts))
f.write(bytes([0x4D, 0xE6]))
f.write(struct.pack('>H', numNorms))
f.write(struct.pack('%sf' % numNorms, *norms))
f.write(bytes([0x4D, 0xE7]))
f.write(struct.pack('>H', numCrds))
f.write(struct.pack('%sf' % numCrds, *crds))

f.close()

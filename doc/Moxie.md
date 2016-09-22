The Moxie File Format Specification v0.1
========================================

Intro
-----

The Moxie file format is designed to save time, memory and
processor utilization by providing a consistent binary format
for 3D models. It accomplishes this by using an open source
file structure such that there isn't a need to design a
complex binary file type for every game or CAD tool.

Layout
------

All Moxie files are structured in the same way:
* Moxie file header
* Vertex Array
* Texture Coord Array
* Normalized Vertex Array
* Armature Array (Still in development)

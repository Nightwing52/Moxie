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

Each section has a section header that identifies the section
and lists the size of that section in a two byte value (4 bytes
total). Each value (except the section header) is stored in a
4 byte floating point value. The resulting tree structure is as follows:

* 0xFE4D4F58 (File Header)
* 0x4DE5 (Vertex section)
* 0x4DE6 (Texture Coordinate section)
* 0x4DE7 (Normalized Vertex section)
* 0x4DE8 (Armature section)

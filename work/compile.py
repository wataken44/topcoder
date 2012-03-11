#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" compile.py


"""

import sys
import os

def compile_main():
    exedir = 'exe'
    destdir = exedir + "/"
        
    src = sys.argv[1]
    dest_obj = destdir + os.path.splitext(os.path.basename(src))[0] + ".o"
    dest_exe = destdir + os.path.splitext(os.path.basename(src))[0] + ".exe"
    
    cmd = "g++ -O0 -g -Wall -c %s -o %s"%(src, dest_obj)
    print(cmd)
    ret = os.system(cmd)

    if(ret == 0):
        cmd = "g++ %s -o %s"%(dest_obj, dest_exe)
        print( cmd)
        os.system(cmd)

if __name__ == "__main__":
    compile_main()

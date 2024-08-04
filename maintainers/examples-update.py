#! bin/python3

import os
import shutil
import glob


def rm_dir_contents(path):
    files = glob.glob(path + '/*')
    for f in files:
        os.remove(f)


# change to the directory of the script
os.chdir(os.path.dirname(os.path.realpath(__file__)))


rm_dir_contents('../examples/bb1-c/src/BeButton1')
rm_dir_contents('../examples/bb1-cpp/src/BeButton1')

shutil.copytree('../src/bb1/bb1-c/', '../examples/bb1-c/src/BeButton1/', dirs_exist_ok=True)
shutil.copytree('../src/bb1/bb1-cpp/', '../examples/bb1-cpp/src/BeButton1/', dirs_exist_ok=True)



# Refactor code: Not timed (good to get it back within 24 hours)
# Aim for production quality ‘best-practice/clean’ code.
# Please explain/show how you would test.
#
# The requirements of the code is to update the build number in
# two different files.
"""
import os
import re


# #SCONSTRUCT file interesting line
# config.version = Version(
#     major=15,
#     minor=0,
#     point=6,
#     patch=0
#)

def updateSconstruct():
    os.chmod(os.path.join(os.environ["SourcePath"],"develop","global","src","SConstruct"), 0755)
    fin = open(os.path.join(os.environ["SourcePath"],"develop","global","src","SConstruct"), 'r')
    fout = open(os.path.join(os.environ["SourcePath"],"develop","global","src","SConstruct1"), 'w')

    for line in fin:
        pattern=re.sub("point\=[\d]+","point="+os.environ["BuildNum"],line)
        fout.write(pattern)
    fin.close()
    fout.close()
    os.remove(os.path.join(os.environ["SourcePath"],"develop","global","src","SConstruct"))
    os.rename(os.path.join(os.environ["SourcePath"],"develop","global","src","SConstruct1"),
              os.path.join(os.environ["SourcePath"],"develop","global","src","SConstruct"))

# # VERSION file interesting line
# ADLMSDK_VERSION_POINT=6
def updateVersion():
    os.chmod(os.path.join(os.environ["SourcePath"],"develop","global","src","VERSION"), 0755)
    fin = open(os.path.join(os.environ["SourcePath"],"develop","global","src","VERSION"), 'r')
    fout = open(os.path.join(os.environ["SourcePath"],"develop","global","src","VERSION1"), 'w')

    for line in fin:
        pattern=re.sub("ADLMSDK_VERSION_POINT\=[\d]+","ADLMSDK_VERSION_POINT="+os.environ["BuildNum"],line)
        fout.write(pattern)
    fin.close()
    fout.close()
    os.remove(os.path.join(os.environ["SourcePath"],"develop","global","src","VERSION"))
    os.rename(os.path.join(os.environ["SourcePath"],"develop","global","src","VERSION1"),
              os.path.join(os.environ["SourcePath"],"develop","global","src","VERSION"))


def main():
    updateSconstruct()
    updateVersion()


main()
"""


# ============================
import os,re

class FileMeta(object):
    def __init__(self):
        # TODO can be used to initialize const value instead of using environment variable
        pass

    def getFullPath(self, fn):
        return os.path.join(os.environ["SourcePath"],"develop","global","src",fn)

    def doUpdate(self, src, pattern):
        src = self.getFullPath(src)
        dst = self.getFullPath(src+"1")

        os.chmod(src, 0755)
        with open(src,'r') as fin:
            with open(dst,'w') as fout:
                for line in fin:
                    pattern=re.sub(pattern,line)
                    fout.write(pattern)

        os.remove(src)
        os.rename(dst, src)
        pass

    def updateSconstruct(self,src):
        pattern = "point\=[\d]+","point="+os.environ["BuildNum"]
        self.doUpdate(src,pattern)
        pass

    def updateVersion(self, src):
        pattern = "ADLMSDK_VERSION_POINT\=[\d]+","ADLMSDK_VERSION_POINT="+os.environ["BuildNum"]
        self.doUpdate(src,pattern)
        pass

    def verify(self,src,pattern):
        fn = self.getFullPath(src)
        with open(fn,'r') as fin:
            for line in fin:
                result = re.match(pattern, line)
                if result:
                    return True
        return False


def main():
    fm = FileMeta()
    fm.updateSconstruct('SConstruct')
    fm.updateVersion('VERSION')
    assert fm.verify('SConstruct',"point\=%s"%os.environ["BuildNum"]), "failed"
    assert fm.verify('VERSION',"ADLMSDK_VERSION_POINT\=%s"%os.environ["BuildNum"]), "failed"


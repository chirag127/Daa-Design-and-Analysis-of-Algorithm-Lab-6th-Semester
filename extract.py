# daa.zip extract

import zipfile


def extractFile(zFile):
    try:
        zFile.extractall()
    except:
        pass


def main():
    zFile = zipfile.ZipFile("daa.zip")
    extractFile(zFile)


if __name__ == "__main__":
    main()

#!/usr/bin/python3

'''
Prints stats of parsed logs from stdin
'''

if __name__ == '__main__':
    import sys

    statusDict = {"200": 0, "301": 0, "400": 0, "401": 0,
                  "403": 0, "404": 0, "405": 0, "500": 0}
    numLines, fileSize = 0, 0

    def printStats(statusDict, fileSize):
        print("File size: {}".format(fileSize))
        for k, v in sorted(statusDict.items()):
            if v:
                print("{}: {}".format(k, v))

    try:
        for line in sys.stdin:
            lineArr = line.split()
            try:
                status = lineArr[-2]
                if status in statusDict.keys():
                    statusDict[status] += 1
            except BaseException:
                pass
            try:
                fileSize += int(lineArr[-1])
            except BaseException:
                pass
            numLines += 1
            if numLines % 10 == 0:
                printStats(statusDict, fileSize)
        printStats(statusDict, fileSize)
    except KeyboardInterrupt:
        printStats(statusDict, fileSize)
        raise

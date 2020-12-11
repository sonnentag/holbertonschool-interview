#!/usr/bin/python3
""" check for keys to all boxes """


def canUnlockAll(boxes):
    ''' canUnlockAll '''

    numboxes = len(boxes)
    unlocked = {0}
    keylist = [0]

    if numboxes > 0:
        while keylist:
            nextlock = keylist.pop()
            for nextkey in boxes[nextlock]:
                if 0 <= nextkey <= numboxes and nextkey not in unlocked:
                    unlocked.add(nextkey)
                    keylist.append(nextkey)
    else:
        return True

    return numboxes == len(unlocked)

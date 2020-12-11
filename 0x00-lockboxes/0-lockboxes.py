#!/usr/bin/python3
""" check for keys to all boxes """


def canUnlockAll(boxes):
    ''' canUnlockAll '''

    numboxes = len(boxes)
    ''' if no boxes, go no further '''
    if numboxes == 0:
        return True

    ''' box 0 is already unlocked '''
    unlocked = {0}
    keylist = [0]

    ''' iterate through new boxen as they are unlocked/added '''
    while keylist:
        nextlock = keylist.pop()
        for nextkey in boxes[nextlock]:

            ''' add distinct new keys/boxen to keylist and unlocked set '''
            if 0 <= nextkey <= numboxes and nextkey not in unlocked:
                keylist.append(nextkey)
                unlocked.add(nextkey)

    ''' true if all boxes have been unlocked '''
    return numboxes == len(unlocked)

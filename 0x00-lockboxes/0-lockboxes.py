#!/usr/bin/python3


def canUnlockAll(boxes):
    final_box = len(boxes)
    checked_keys = {0}
    unopened_boxes = []
    unopened_boxes.append(0)

    while (len(checked_keys) < final_box and len(unopened_boxes) > 0):
        next_unchecked = []
        for box in unopened_boxes:
            for key in boxes[box]:
                if (key not in checked_keys and key > 0 and key < final_box):
                    checked_keys.add(key)
                    next_unchecked.append(key)
        unopened_boxes = next_unchecked

    if len(checked_keys) == final_box:
        return True
    return False


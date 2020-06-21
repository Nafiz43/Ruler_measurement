# Ruler Measurement

Use 2 sticks of length 5 inch and 7 inch to measure a length of 1
inch. The sticks can’t be broken.

![scale](https://user-images.githubusercontent.com/43680716/85224832-d415ac80-b3ee-11ea-9d22-0b2af8d475ed.png)

## Solution
State Representation:
{P,Q}

Where
P: = Left coordinate of Scale 1
Q: = Left coordinate of Scale 2
From (P, Q), at each step left, middle and right side measurement can be obtained.
For obtaining left, middle and right measurement:
Here,
Scale 1 = 7 inch
Scale 2 = 5 inch
Left = |(x coordinate of left side of scale 1) - (x coordinate of left side of scale 2) |
Middle = | (x coordinate of left side of scale 1 + size of scale 1) – (x coordinate of left side of scale 2) |
Right= |(x coordinate of left side of scale 1 + size of scale 1) - (x coordinate of left side of scale 2 + size of scale 2)|

State Mapping Tree :
Actions taken at each node (from left to right):
1. Turn over Scale 1 to Left
2. Turn over Scale 2 to Left
3. Turn over Scale 1 to Right
4. Turn over Scale 2 to Right



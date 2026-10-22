"""
Synthetic-image drivable-region demo for learning OpenCV basics.
This is NOT the original ROS 2/CARLA project and is NOT a validated road detector.
Run: python laneless_opencv_demo.py
Requires: opencv-python, numpy
"""
import cv2
import numpy as np

# Generate a simple synthetic scene so the demo runs without camera footage.
img = np.zeros((480, 640, 3), dtype=np.uint8)
img[:] = (75, 95, 80)                         # greenish surrounding area
cv2.fillPoly(img, [np.array([[170,480],[270,190],[370,190],[510,480]])], (90,90,90))
# Add irregular roadside features; no lane markings are drawn.
cv2.rectangle(img,(60,250),(135,420),(30,130,40),-1)
cv2.rectangle(img,(510,230),(600,430),(35,120,45),-1)
hsv=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
# A simplistic gray-road mask for this synthetic image only.
mask=cv2.inRange(hsv,np.array([0,0,35]),np.array([180,80,150]))
overlay=img.copy()
overlay[mask>0]=(0,180,255)
combined=cv2.addWeighted(img,0.65,overlay,0.35,0)
cv2.putText(combined,"SYNTHETIC DEMO - NOT ROAD-VALIDATED",(12,28),cv2.FONT_HERSHEY_SIMPLEX,.55,(255,255,255),2)
cv2.imshow("Synthetic input",img)
cv2.imshow("Threshold mask",mask)
cv2.imshow("Overlay",combined)
cv2.waitKey(0)
cv2.destroyAllWindows()

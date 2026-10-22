"""
Illustrative differential-drive obstacle-avoidance path.
This is a simple plotted example path, not a physics simulator or ROS 2 implementation.
Run: python differential_drive_demo.py
Requires: matplotlib, numpy
"""
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Circle

obstacles = [(4,4,0.8), (6.5,6.5,0.9), (3,7,0.6)]
path = np.array([[1,1],[1.5,1.5],[2,2.1],[2.6,2.8],[3.1,3.4],
                 [3.3,4.0],[3.1,4.7],[3.4,5.3],[4,5.8],[4.8,6.0],
                 [5.5,6.2],[6.1,6.7],[6.7,7.2],[7.5,7.8],[8.5,8.6]])
fig, ax = plt.subplots(figsize=(7,6))
for x,y,r in obstacles:
    ax.add_patch(Circle((x,y),r,color="#E8A17D",alpha=.75,label="Obstacle" if (x,y)==obstacles[0][:2] else None))
ax.plot(path[:,0],path[:,1],"-o",color="#00A99A",label="Illustrative path")
ax.scatter([path[0,0]],[path[0,1]],marker="s",s=80,color="#12263A",label="Start")
ax.scatter([path[-1,0]],[path[-1,1]],marker="*",s=150,color="#D9822B",label="Goal")
ax.set(xlim=(0,10),ylim=(0,10),xlabel="x (m)",ylabel="y (m)",title="Differential-drive navigation concept")
ax.set_aspect("equal"); ax.grid(True,alpha=.25); ax.legend(); fig.tight_layout()
plt.show()

## Installation  
```python
pip install open3d-python
```

## Operation  
```python
import open3d as o3d

# Read
ply = o3d.io.read_point_cloud("8_Couple.ply")

# Write
o3d.io.write_point_cloud("8_Couple_copy.ply", ply)

# Set Color
np.asarray(ply.colors)[0,:]=[255,0,0]

# Visualization
o3d.visualization.draw_geometries([ply])  
```
import sys

import vicon_dssdk

client = vicon_dssdk.DataStreamClient()
result = client.Connect(sys.argv[1])
print(f"Connection result: {result.Result}")
result = client.EnableSegmentData()
print(f"Enable Segment Data result: {result.Result}")
result = client.GetFrame()
print(f"Get Frame result: {result.Result}")
result = client.GetSubjectCount()
print(f"Get Subject Count result: {result}")
subject_name = client.GetSubjectName(0)
print(f"Subject name: {subject_name}")
result = client.GetFrame()
result = client.GetSegmentLocalTranslation(subject_name, "Hips")
print(f"Root translation: {result}")
result = client.GetSegmentLocalRotationQuaternion(subject_name, "Hips")
print(f"Root rotation (quaternion): {result}")
result = client.GetSegmentLocalRotationEulerXYZ(subject_name, "Hips")
print(f"Root rotation (Euler XYZ): {result}")

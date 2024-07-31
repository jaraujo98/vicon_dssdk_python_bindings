import sys

import vicon_dssdk

client = vicon_dssdk.DataStreamClient()
result = client.connect(sys.argv[1])
print(f"Connection result: {result.Result}")
result = client.enable_segment_data()
print(f"Enable Segment Data result: {result.Result}")
result = client.get_frame()
result = client.get_frame()
print(f"Get Frame result: {result.Result}")
result = client.get_subject_count()
print(f"Get Subject Count result: {result}")
subject_name = client.get_subject_name(0)
print(f"Subject name: {subject_name}")
result = client.get_segment_local_translation(subject_name, "Hips")
print(f"Root translation: {result}")

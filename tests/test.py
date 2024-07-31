import sys

import vicon_dssdk

client = vicon_dssdk.DataStreamClient()
result = client.connect(sys.argv[1])
print(f"Connection result: {result.Result}")
result = client.get_frame()
print(f"Get Frame result: {result.Result}")

import sys

import vicon_dssdk

client = vicon_dssdk.DataStreamClient()
result = client.connect(sys.argv[1])
print(result.Result)

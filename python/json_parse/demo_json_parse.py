# import json
# import pprint

# employee_dict=None
# user=None



# def find_setup(employee_dict):
#         for each_item in employee_dict.items():
#             if isinstance(each_item, dict):
#                 find_setup()
#             else:
#                 print(each_item)
                
#             #for k, v in employee_dict.items():
#             #    print(k)
#                 #for k2, v2 in k:
#                 #    if k2 == 'user':
#                 #        user = v2
    
# #pprint(user)

# with open('config.json', 'r', encoding='utf-8') as file_object:
#         employee_dict = json.load(file_object)
#         find_setup(employee_dict)
        

from __future__ import print_function
import json

def dict_generator(indict, pre=None):
    pre = pre[:] if pre else []
    if isinstance(indict, dict):
        for key, value in indict.items():
            if isinstance(value, dict):
                if len(value) == 0:
                    yield pre+[key, '{}']
                else:
                    for d in dict_generator(value, pre + [key]):
                        yield d
            elif isinstance(value, list):
                if len(value) == 0:                   
                    yield pre+[key, '[]']
                else:
                    for v in value:
                        for d in dict_generator(v, pre + [key]):
                            yield d
            elif isinstance(value, tuple):
                if len(value) == 0:
                    yield pre+[key, '()']
                else:
                    for v in value:
                        for d in dict_generator(v, pre + [key]):
                            yield d
            else:
                yield pre + [key, value]
    else:
        yield indict

if __name__ == "__main__":
    sJOSN='config.json'
    with open(sJOSN, 'r', encoding='utf-8') as f:
        sValue = json.load(f)
        for i in dict_generator(sValue):
            print('.'.join(i[0:-1]), ':', i[-1])

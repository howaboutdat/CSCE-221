import json

data = {}
data['students'] = []
data['students'].append({
    'name': 'Quy Dao',
    'GitHubID': 'https://github.com/howaboutdat',
    'NetID': 'quydao1462'
})

with open('identity.txt', 'w') as outfile:
    json.dump(data, outfile)
    
with open('identity.txt') as json_file:
    data = json.load(json_file)
    for student in data['students']:
        print('Name: ' + student['name'])
        print('GitHubID: ' + student['GitHubID'])
        print('NetID: ' + student['NetID'])
        print('')
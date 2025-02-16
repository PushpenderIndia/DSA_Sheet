import json
import pandas as pd
import requests

# r = requests.get("https://premium-backend.takeuforward.org/api/v2/course/allSyllabus/dsa")
# data = r.json()
with open('dsa.json') as f:
    data = json.load(f)
    
roadmap = data['roadmap']
categories = roadmap['categories']

final_data = []

for category in categories:
    subcategories = category['subcategories']
    for subcategory in subcategories:
        problems = subcategory['problems']
        for problem in problems:
            problem_id = problem['problem_id']
            problem_id = problem_id.replace('/', '%2F')
            url = f'https://premium-backend.takeuforward.org/api/v2/course/problem/getDetails/{problem_id}'
            response = requests.get(url)
            problem = response.json()
            final_data.append({
                'Category': category['category_name'],
                'Subcategory': subcategory['subcategory_name'],
                'Problem': problem['problem_name'],
                'URL': problem['url'],
                'Is_completed': problem['is_completed'],
            })

df = pd.DataFrame(final_data)
df.to_csv('dsa.csv', index=False)
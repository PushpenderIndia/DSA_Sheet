import json
import pandas as pd

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
            final_data.append({
                'category': category['category_name'],
                'subcategory': subcategory['subcategory_name'],
                'problem': problem['problem_name'],
                'is_completed': problem['is_completed']
            })

df = pd.DataFrame(final_data)
df.to_csv('dsa.csv', index=False)
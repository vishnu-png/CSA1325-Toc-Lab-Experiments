# Install mlxtend library if not already installed
# pip install mlxtend

from mlxtend.frequent_patterns import apriori
from mlxtend.frequent_patterns import association_rules
import pandas as pd

# Sample transaction data
data = {'TransactionID': [1, 1, 2, 2, 2, 3, 3, 4, 4, 4],
        'Item': ['Milk', 'Bread', 'Milk', 'Diapers', 'Beer',
                 'Bread', 'Diapers', 'Milk', 'Bread', 'Diapers']}
df = pd.DataFrame(data)

# Convert transaction data to one-hot encoded format
basket = (df
          .groupby(['TransactionID', 'Item'])['Item']
          .count().unstack().reset_index().fillna(0)
          .set_index('TransactionID'))

# Convert item counts to binary values
basket_encoded = basket.applymap(lambda x: 1 if x > 0 else 0)

# Generate frequent itemsets using Apriori algorithm
frequent_itemsets = apriori(basket_encoded, min_support=0.5, use_colnames=True)

# Generate association rules
rules = association_rules(frequent_itemsets, metric="lift", min_threshold=1)

print("Frequent Itemsets:")
print(frequent_itemsets)
print("\nAssociation Rules:")
print(rules) 

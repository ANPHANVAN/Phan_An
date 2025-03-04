import pandas as pd
import seaborn as sns
import matplotlib as plt
db = SQL("sqlite:///expensive_app.db")

# import table from database
def import_table():
    return pd.read_sql("SELECT * FROM transactions", db.engine)

transaction = import_table()
print(transaction)
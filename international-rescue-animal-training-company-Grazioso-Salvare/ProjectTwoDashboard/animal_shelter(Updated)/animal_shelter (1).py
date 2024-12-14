#SNHU, Justin D. Perez
#Professor Hari Paruchuri
#June 9, 2024

#Updated & Modifed Code:

from pymongo import MongoClient
from bson.objectid import ObjectId

class AnimalShelter(object):
    # CRUD operations for Animal collection in MongoDB

    def __init__(self, user, password, host, port, db, col):
        # Initialize the MongoClient and connect to the specified database and collection.
        self.client = MongoClient(f'mongodb://{user}:{password}@{host}:{port}')
        self.database = self.client[db]
        self.collection = self.database[col]

    def create(self, data):
        # Insert a document into the specified MongoDB database and collection.
        # Return True if successful insert, else False.
        if data:
            result = self.collection.insert_one(data)
            return True if result.inserted_id else False
        else:
            raise Exception("Nothing to save because data parameter is empty")

    def read(self, query):
        # Query for documents from the specified MongoDB database and collection.
        # Return the result in a list if the command is successful, else an empty list.
        cursor = self.collection.find(query)
        return list(cursor)

    def update(self, query, update_data):
        # Update a document in the specified MongoDB database and collection.
        # Return the number of documents modified.
        if query and update_data:
            result = self.collection.update_many(query, {'$set': update_data})
            return result.modified_count
        else:
            raise Exception("Both query and update_data parameters are required")

    def delete(self, query):
        # Delete documents from the specified MongoDB database and collection.
        # Return the number of documents deleted.
        if query:
            result = self.collection.delete_many(query)
            return result.deleted_count
        else:
            raise Exception("Nothing to delete because query parameter is empty")
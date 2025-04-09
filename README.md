# Supermarket Management System

A C++ project for managing supermarket operations including product inventory, customer information, and sales invoices.

## Project Structure

```
SupermarketSystem/
├── include/                    # Header files
│   ├── Product.h              # Product class definition
│   ├── Customer.h             # Customer class definition
│   ├── InvoiceItem.h          # InvoiceItem class definition
│   ├── Invoice.h              # Invoice class definition
│   ├── SupermarketManager.h   # SupermarketManager class definition
│   └── Utils.h                # Utility functions
│
├── src/                        # Source files
│   ├── Product.cpp            # Product implementation
│   ├── Customer.cpp           # Customer implementation
│   ├── InvoiceItem.cpp        # InvoiceItem implementation
│   ├── Invoice.cpp            # Invoice implementation
│   ├── SupermarketManager.cpp # SupermarketManager implementation
│   ├── Utils.cpp              # Utility functions implementation
│   └── main.cpp               # Main program and user menu
│
└── data/                       # Data files
    ├── products.csv           # Product data
    ├── customers.csv          # Customer data
    └── invoices.csv           # Invoice data
```

## Features

### Product Management
- Add, edit, delete products
- Search products by ID, name, category, price range, manufacturer
- Sort products by various criteria
- Display product statistics

### Customer Management
- Add, edit, delete customers
- Search customers by ID, name, phone, email, membership level
- Sort customers by various criteria
- Display customer statistics

### Invoice Management
- Create new invoices
- Display invoice details
- Search invoices by various criteria
- Sort invoices by various criteria
- Display sales statistics

## Requirements

- C++11 or higher
- GCC/G++ compiler

## How to Build and Run

### Building the Project

Navigate to the project directory and use the Makefile to build:

```
make
```

### Running the Application

After building, run the application:

```
./supermarket
```

Or build and run in one command:

```
make run
```

## Menu System

The application features a menu-driven interface:

1. **Main Menu**
   - Product Management
   - Customer Management
   - Invoice Management
   - Statistics & Reports
   - Exit

2. **Product Management**
   - Display All Products
   - Add New Product
   - Edit Product
   - Delete Product
   - Search Products
   - Sort Products
   - Back to Main Menu

3. **Customer Management**
   - Display All Customers
   - Add New Customer
   - Edit Customer
   - Delete Customer
   - Search Customers
   - Sort Customers
   - Back to Main Menu

4. **Invoice Management**
   - Display All Invoices
   - Create New Invoice
   - Display Invoice Details
   - Search Invoices
   - Sort Invoices
   - Back to Main Menu

5. **Statistics & Reports**
   - Product Statistics
   - Customer Statistics
   - Sales Statistics
   - Back to Main Menu

## Data Persistence

All data is stored in CSV files in the `data/` directory:
- Product information: `data/products.csv`
- Customer information: `data/customers.csv`
- Invoice information: `data/invoices.csv`

## License

This project is created for educational purposes as part of a data structures and algorithms course.

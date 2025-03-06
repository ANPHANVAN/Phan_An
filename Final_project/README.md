# Expense Managment
#### Video Demo: https://youtu.be/Gl0dhY0DrK4 [<URL HERE>](https://youtu.be/Gl0dhY0DrK4)
#### Description:

### Introduction
I have developed an expense management website using Python Flask, HTML, CSS, JavaScript, and SQL. The primary goal of this project is to help users easily record their daily expenses and income while providing visual reports to help them better understand their financial situation. The website has a user-friendly interface, making it accessible to everyone.

This project was inspired by the common problem of tracking personal finances. Many individuals struggle with managing their income and expenses effectively, leading to financial instability. By developing this website, I aimed to provide a simple yet efficient tool that enables users to take control of their financial activities. The system is designed to be intuitive, ensuring that both tech-savvy and non-tech-savvy users can navigate and utilize its features without difficulty.

### Key Features
The website offers various features to support effective financial management:
1. **Recording Expenses and Income**: Users can enter their transactions on the "Adds" page.
   - The expense section includes: amount, category, date, and notes.
   - The income section includes: amount, category, date, and notes.
   - These entries allow users to maintain a detailed history of their financial transactions, which can be useful for budgeting and future financial planning.
2. **Visual Reports**:
   - The "Home" page displays two trending reports, showing spending and income trends over time.
   - A third chart allows users to select a time range (day, week, month, or year). Choosing "Year" will display a bar chart comparing expenses across different years.
   - These reports help users quickly identify spending patterns and make informed decisions about their finances.
3. **Cash Balance Management**: Displays the user’s current balance, calculated as total income minus total expenses.
4. **Flexible Data Filtering**:
   - The "Filter" page has two tables that allow sorting by date, amount, or category, in ascending or descending order.
   - Users can filter data by time range: day, week, month, or year.
   - This feature ensures that users can retrieve and analyze their financial data with ease, enhancing usability.
5. **Transaction Management**:
   - The "Transaction" page contains two separate tables for expenses and income.
   - Users can filter transactions by selecting a start date and an end date.
   - This feature is particularly useful for users who need to review past transactions for tax purposes or financial analysis.
6. **Admin Settings**:
   - The "Settings" page allows the admin to manage expense and income categories.
   - Admins can add or delete categories using a "Delete" button.
   - By allowing admins to modify categories, the system ensures flexibility to accommodate different financial tracking needs.
7. **User Authentication & Security**:
   - Users can register, log in, and log out securely.
   - Passwords are hashed before being stored for enhanced security.
   - Ensuring secure authentication is crucial for protecting sensitive financial data from unauthorized access.

### Database Structure
The website uses SQLite3 for data storage. The database consists of four main tables:
- **Users**: Stores user account information, including username, hashed password, and cash balance.
- **Transactions**: Records user transactions, including user_id, category, amount, and date.
- **Categories**: Stores expense categories.
- **Categories_salary**: Stores income categories.

By structuring the database efficiently, the website ensures quick access and retrieval of financial data while maintaining data integrity.

### Technologies Used
Apart from Flask as the backend framework and SQLite3 as the database, I used the following libraries:
- **CS50**: Helps with database handling and form processing.
- **Werkzeug.security**: Used for password hashing to enhance security.
- **Pandas**: Supports data processing and report generation.
- **Custom-built library**: Contains functions to optimize data handling.

Using these technologies, I was able to create a robust, secure, and efficient system that provides a seamless user experience.

### Challenges During Development
As this is my first web development project, I faced several challenges, particularly in optimizing my code. Initially, my code was quite disorganized, making it difficult to maintain and extend. However, throughout the development process, I learned to structure my code better, use functions and modules efficiently, and improve reusability.

Additionally, designing a responsive and interactive user interface was another challenge. Ensuring that the website functions well across different devices and screen sizes required testing and debugging. I also had to work on improving database queries to enhance performance, especially when filtering large amounts of data.

Another major challenge was implementing secure authentication and data protection measures. Since financial data is sensitive, I had to ensure proper password hashing and implement best practices in securing user information.

### Future Enhancements
In the future, I plan to enhance the reporting system to provide more useful financial insights. My intended improvements include:
- **More detailed analytical charts** to help users understand spending patterns in different categories.
- **AI-based saving suggestions** to assist users in better financial management.
- **Exporting data to CSV or Excel files**, enabling users to manage their finances in more detail.
- **A budgeting feature** that allows users to set financial goals and track their progress.
- **Mobile app integration**, allowing users to access and manage their finances on the go.
- **Multi-user support**, enabling families or small businesses to track shared expenses collaboratively.

By implementing these improvements, I aim to make the platform more powerful and user-friendly.

### Conclusion
This expense management website is my first project in web development. It has not only helped me gain a deeper understanding of Flask, SQL, and JavaScript but also improved my skills in UI design, data handling, and code optimization. I believe that with future improvements, this website will become a valuable tool for users to manage their personal finances more efficiently.

Throughout this project, I have learned the importance of writing clean, modular code, designing an intuitive user experience, and implementing secure data practices. The journey of building this website has been an enriching experience, and I look forward to applying these skills in future projects.
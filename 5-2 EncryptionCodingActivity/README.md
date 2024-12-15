# Secure Authentication System (CS 405: Secure Coding)

## Project Overview
The Secure Authentication System is a project designed to implement robust measures against common vulnerabilities in authentication processes. It ensures that sensitive user credentials are protected while maintaining usability. The project focuses on enhancing the security of user login mechanisms, protecting data integrity, and preventing unauthorized access.

## Enhancements
- **Password Security**: Implemented SHA-256 hashing with salts to securely store passwords, reducing the risk of password theft and brute-force attacks.
- **Input Validation**: Added thorough validation for user inputs to eliminate vulnerabilities such as SQL injection and cross-site scripting (XSS).
- **Two-Factor Authentication (2FA)**: Designed and integrated an additional layer of security by requiring a time-based one-time password (TOTP) for login.

## Tools & Technologies
- **Programming Language**: Java
- **Framework**: Spring Security
- **Development Environment**: IntelliJ IDEA
- **Libraries**: Apache Commons Codec (for hashing), Google Authenticator (for TOTP)

### Why This Artifact Was Chosen
This artifact was selected because it demonstrates the critical application of secure coding practices in software development. Authentication systems are a foundational element of modern applications, and this project reflects the importance of building systems that anticipate and mitigate potential exploits.

### How the Enhancements Improved the Artifact
The enhancements improved the artifact by ensuring that it adheres to best practices for secure software design. By addressing vulnerabilities proactively, the project showcases a strong understanding of security concepts and their practical application. The improvements make the system more reliable and scalable for real-world deployment.

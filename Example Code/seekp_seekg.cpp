   fstream file("example.txt", ios::in | ios::out | ios::trunc);

   if (!file) {
       cerr << "Error opening file!" << endl;
       return 1;
   }

   // Write initial content
   file << "Hello, World!" << endl;
   file << "This is a test file." << endl;

   // Move to the beginning of the file
   file.seekg(0, ios::beg);

   // Read and display the content
   string line;
   while (getline(file, line)) {
       cout << line << endl;
   }
   file.close();
   file.open("example.txt", ios::out);
   // Move to a specific position and modify content
   file.seekp(0);
   file << "C++";

   // Move to the end and append content
   file.seekp(0, ios::end);
   file << "Appended text." << endl;

   // Read and display the modified content
   file.seekg(0, ios::beg);
   cout << "\nModified content:\n";
   while (getline(file, line)) {
       cout << line << endl;
   }

   file.close();
   return 0;
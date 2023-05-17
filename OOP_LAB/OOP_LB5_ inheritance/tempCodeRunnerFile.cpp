}
    {
        char *test;
        test = a;
        cout << "char*(a); " << test << endl;
        test[2] = 'n';
        // delete[] test;
    }
    cout << "Did a chanced? " << a << endl;
    {
        int *test1;
        test1 = a;

        for (int i = 0; i < a.Size(); i++)
            cout << test1[i] << " ";

        test1[2] = 2;
        delete[] test1;
    }
    cout << "\nDid a chanced? " << a << endl;
    {
        a.AStringToUpperCase();
        cout << a << endl;
        a.AStringToLowerCase();
        cout << a << endl;
    }
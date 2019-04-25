void HandleMenuSelection(CCalc &calc, char menuItem)
{
    CalcType temp;
    
    switch (toupper(menuItem))
    case 'Q':
        cout << "Bye!";
        break;
    case 'C':
        ccalc.Clear();
        break;
    case 'T':
        cout << "Please enter a new value to assign: "
        cin >> temp;
        calc.SetValue(temp);
        break;
    case 'V':
        cout << "The current value is " << ccalc.GetValue() << endl;
        break;
    case 'A':
        cout << "Please enter a value to add: ";
        cin >> temp;
        calc.Add(temp);
        break;
    case 'S':
        cout << "Please enter a value to subtract: ";
        cin >> temp;
        calc.Subtract(temp);
        break;
    case 'D':
        cout << "Please enter a divisor: ";
        cin >> temp;
        if (0 == temp)
        cout << "Cannot divide by zero";
        else
        calc.Divide(temp);
        break;
    default:
        cout << "Unrecognized response; try again...\n";
        break;
}
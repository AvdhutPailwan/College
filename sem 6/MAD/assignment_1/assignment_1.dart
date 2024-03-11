// TYB22 Avdhut Pailwan
// 2122000380

import 'dart:io';

void main() {
  // 1. Declare constant type of int set value 7
  const int i = 7;
  print(i);
  print('\n');

  // 2. Write a program in Dart that finds simple interest. Formula = ( p * t * r ) / 100
  print("Principle: ");
  var p = double.tryParse(stdin.readLineSync()!);
  print("Number of years: ");
  var t = double.tryParse(stdin.readLineSync()!);
  print("Rate of interest: ");
  var r = double.tryParse(stdin.readLineSync()!);
  print("The simple interest is : ${simple_interest(p, t, r)}");
  print('\n');

  // 3. Write a program to print a square of a number using user input
  print("Enter a number: ");
  var input = double.tryParse(stdin.readLineSync()!);
  print("The square of the $input is: ${square(input)}");
  print('\n');

  // 4. Write a program to print full name of a from first name and last name using user input
  print('First Name: ');
  var first_name = stdin.readLineSync();
  print('Last Name: ');
  var last_name = stdin.readLineSync();
  print('Full Name: $first_name $last_name');
  print('\n');

  // 5. Write a program to find quotient and remainder of two integers
  print('First Number: ');
  var a = double.parse(stdin.readLineSync()!);
  print('Second Number: ');
  var b = double.parse(stdin.readLineSync()!);
  print('Quotient of $a and $b: ${a / b}');
  print('Remainder of $a and $b: ${a % b}');
  print('\n');

  // 6. Write a program to swap two numbers
  print('Enter First Number c: ');
  var c = int.parse(stdin.readLineSync()!);
  print('Enter Second Number d: ');
  var d = int.parse(stdin.readLineSync()!);
  print('c: $c\td: $d');
  c = c + d;
  d = c - d;
  c = c - d;
  print('After swapping...\nc: $c\td: $d');
  print('\n');

  // 7. Write a program in Dart to remove all whitespaces from string
  var str = "KIT's College of Engineering(Autonomous), Kolhapur";
  str = str.replaceAll(RegExp(r' '), '');
  print(str);
  print('\n');

  // 8. Write a Dart program to convert String to int
  String str2 = '12345';
  num n = int.parse(str2);
  print('\n');

  // 9. Suppose, you often go to restaurant with friends and you have to split amount of bill
  //    Write a program to calculate split amount of bill.
  //    Formula = (total bill amount)/(number of people)
  print('total amount of bill: ');
  var bill = double.parse(stdin.readLineSync()!);
  print('Number of people in the group: ');
  var no_of_people = int.parse(stdin.readLineSync()!);
  print('Pay amount per person: ${bill / no_of_people}');
  print('\n');

  // 10. Suppose your distance from home is 25km and you travel 40km per hour. Write a program
  //     to calculate time taken to reach office in minutes.
  //     Formula = (distance)/(speed)
  print('distance: ');
  var distance = double.parse(stdin.readLineSync()!);
  print('speed: ');
  var speed = double.parse(stdin.readLineSync()!);
  print('Time Taken to reach target: ${distance / speed}');
  print('\n');
}

double simple_interest(double? p, double? t, double? r) {
  return (p! * t! * r!) / 100;
}

double square(double? n) {
  return n! * n;
}

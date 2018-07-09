/*DROP TABLE EMPLOYEE;
DROP TABLE DESIGNATION;
DROP TABLE DEPARTMENT;

CREATE TABLE EMPLOYEE
( EMP_CODE char(5),
EMP_NAME char(20),
DEPT_CODE char(5),
DESIG_CODE char(5),
GENDER char(1),
ADDRESS char(25),
CITY char(20),
STATE char(20),
PIN char(6),
BASIC int,
JN_DT Date,
PRIMARY KEY (EMP_CODE)
);
CREATE TABLE DESIGNATION
(
DESIG_CODE char(5),
DESIG_DESC char(20),
PRIMARY KEY (DESIG_CODE)
);
CREATE TABLE DEPARTMENT
(
  DEPT_CODE char(5),
DEPT_NAME char(15),
PRIMARY KEY (DEPT_CODE)
 );
DESC EMPLOYEE
INSERT INTO DESIGNATION
   (DESIG_CODE,DESIG_DESC)
   VALUES
   (&DESIG_CODE,&DESIG_DESC);

INSERT INTO DEPARTMENT
   (DEPT_CODE,DEPT_NAME)
   VALUES
   (&DEPT_CODE,&DEPT_NAME); 
*/


INSERT INTO EMPLOYEE
   (EMP_CODE,EMP_NAME,DEPT_CODE,DESIG_CODE, GENDER,ADDRESS, CITY, STATE,PIN,BASIC,JN_DT)
   VALUES
   ('1028','RSS','201','102','F','Gateway road the','kolkata','india','124133',122000,'1 march 2010');
   
   




/*(1002 ,'Ramesh',204,102,'M','9482 Consectetuer Rd.','Berlin','Berlin',20,000,'750733','12 jan 1997')
(1003,'Hanae',204,103,'F','328-4327 Dis Rd.','Bismil','Maharashtra',30000,'704691','14 march 2015')
(1004,'Xyla',205,101,'F','357-6904 Aliquam Avenue', 'Kolkata', 'West bengal',30,000,'123833','13 jan 2013')
(1005,'Brett',201,105,'M','Ap #320-6958 Felis Road','Lucknow', 'Luxemburg' 	2491
Dalton 	570-393 Lectus	 St. 	Sabadell 	CA 
Edward 	420-7702 Arcu St. 	Tczew 	PM 	9301
Jennifer 	821-9269 Euismod St. 	Lourdes 	Manitoba 	2946
Ashton 	154-7314 Pede Street 	Knoxville 	Tennessee 	5531
Octavia 	Ap #943-6037 Luctus Avenue 	A Coruña 	Galicia 	9265
Olga 	P.O. Box 808	 1446 Ut Avenue 	Diadema 	São Paulo 
Valentine 	8400 Mauris Road 	Huelva 	AN 	7863
Hasad 	P.O. Box 344	 8197 Nunc Rd. 	Dutse 	JI 
Elton 	397-143 Neque Road 	Sint-Joost-ten-Node 	Brussels Hoofdstedelijk Gewest 	7566
Cruz 	724-7736 Tristique St. 	Naperville 	Illinois 	5305
*/   
DESC DEPARTMENT
DESC DESIGNATION
DESC EMPLOYEE
SELECT * FROM DEPARTMENT;
SELECT * FROM DESIGNATION;
SELECT * FROM EMPLOYEE;


update EMPLOYEE set BASIC=0 where BASIC IS null;
SELECT * FROM EMPLOYEE WHERE BASIC=0;
SELECT * FROM EMPLOYEE WHERE BASIC IS null;
SELECT avg(BASIC) from EMPLOYEE;
DELETE FROM EMPLOYEE WHERE DEPT_CODE = '201';
SELECT upper(EMP_NAME),BASIC*1.8 AS SALARY,DEPT_CODE FROM EMPLOYEE ORDER BY DEPT_CODE DESC;
SELECT * FROM EMPLOYEE WHERE JN_DT>'1 JAN 2013';
SELECT COUNT(EMP_NAME) FROM EMPLOYEE WHERE EXTRACT(month FROM JN_DT)=1;
SELECT MAX(BASIC) from EMPLOYEE;
SELECT MIN(BASIC) from EMPLOYEE;
SELECT COUNT(GENDER) FROM EMPLOYEE WHERE GENDER='F';

SELECT DISTINCT CITY FROM EMPLOYEE;
SELECT * FROM EMPLOYEE ORDER BY DEPT_CODE ASC;
UPDATE EMPLOYEE set CITY=upper(CITY);




/*assignment 2*/
INSERT INTO EMPLOYEE
   (EMP_CODE,EMP_NAME,DEPT_CODE,DESIG_CODE, GENDER,ADDRESS, CITY, STATE,PIN,BASIC,JN_DT)
   VALUES
   ('1028','RSS','201','102','F','Gateway road the','kolkata','india','124133',122000,'1 march 2010');

/*1.From the EMPLOYEE table show the minimum, maximum, and average basic for each
department.*/
SELECT DEPT_CODE,MAX(BASIC) AS MAXIMUM,MIN(BASIC) AS MINIMUM,AVG(BASIC) AS AVERAGE 
from EMPLOYEE 
GROUP BY DEPT_CODE 
ORDER BY DEPT_CODE ASC;

/*2.Find the number of female employees in each department.*/
SELECT COUNT(EMP_CODE) as female_emp,DEPT_CODE 
from EMPLOYEE 
WHERE GENDER ='F' 
GROUP BY DEPT_CODE;


/*3.Find the city wise no. of employees for each department.*/
SELECT DEPT_CODE,CITY,COUNT(EMP_CODE)
from EMPLOYEE 
GROUP BY DEPT_CODE,CITY 
ORDER BY DEPT_CODE ASC;


/*4.Show the designation wise no. of employees who have joined in the year 2000 in each
department. The listing should appear in the ascending order of no, of employees.*/
SELECT DEPT_CODE,DESIG_CODE,COUNT(EMP_CODE) 
from EMPLOYEE 
WHERE JN_DT LIKE '%00' 
GROUP BY DEPT_CODE,DESIG_CODE 
ORDER BY COUNT(DEPT_CODE) ASC;

/*5.Find the department wise total basic of male employees only for the departments for
which such total is more than 50,000 and the listing should appear in the descending
order of total basic.*/

SELECT DEPT_CODE,SUM(BASIC)
from EMPLOYEE 
WHERE GENDER ='M' 
GROUP BY DEPT_CODE 
HAVING SUM(BASIC)>50000 
ORDER BY SUM(BASIC) DESC;

/*6.Show the employee name, Designation description, basic for all employees*/

SELECT EMPLOYEE.EMP_NAME,DESIGNATION.DESIG_DESC 
FROM EMPLOYEE,DESIGNATION 
WHERE EMPLOYEE.DESIG_CODE=DESIGNATION.DESIG_CODE;

/*7.*/
SELECT EMPLOYEE.EMP_NAME,DESIGNATION.DESIG_DESC,DEPARTMENT.DEPT_NAME,EMPLOYEE.BASIC 
FROM EMPLOYEE,DESIGNATION,DEPARTMENT 
WHERE (EMPLOYEE.DESIG_CODE=DESIGNATION.DESIG_CODE) 
AND (EMPLOYEE.DEPT_CODE=DEPARTMENT.DEPT_CODE);
/*8.*/
SELECT DEPARTMENT.DEPT_CODE 
FROM DEPARTMENT  
WHERE NOT EXISTS(SELECT EMPLOYEE.DEPT_CODE 
FROM EMPLOYEE 
WHERE EMPLOYEE.DEPT_CODE=DEPARTMENT.DEPT_CODE);
/*9.*/
SELECT DEPARTMENT.DEPT_NAME 
FROM DEPARTMENT 
WHERE EXISTS(SELECT EMPLOYEE.DEPT_CODE 
FROM EMPLOYEE 
WHERE EMPLOYEE.DEPT_CODE=DEPARTMENT.DEPT_CODE);

/*10.*/
SELECT DEPARTMENT.DEPT_NAME 
FROM DEPARTMENT 
WHERE DEPT_CODE IN (SELECT DISTINCT EMPLOYEE.DEPT_CODE
FROM EMPLOYEE
GROUP BY DEPT_CODE
HAVING COUNT(DEPT_CODE)>=5);


/*11.*/
SELECT DEPT_CODE 
FROM EMPLOYEE
WHERE BASIC=(SELECT MAX(BASIC) FROM EMPLOYEE);

/*12.*/
SELECT DESIG_DESC
FROM DESIGNATION 
WHERE DESIG_CODE =(SELECT EMPLOYEE.DESIG_CODE 
FROM EMPLOYEE
WHERE BASIC=(SELECT MAX(BASIC) FROM EMPLOYEE));


/*13.*/
SELECT DEPT_CODE,COUNT(EMP_CODE) 
FROM EMPLOYEE
WHERE DESIG_CODE='101'
GROUP BY EMPLOYEE.DEPT_CODE;     



/*14.*/
SELECT EMP_NAME,BASIC 
FROM EMPLOYEE 
WHERE BASIC >= ALL(SELECT DISTINCT BASIC FROM EMPLOYEE);

/*6.*/
SELECT EMP_NAME,BASIC 
FROM EMPLOYEE 
WHERE  BASIC <= ALL(SELECT DISTINCT BASIC FROM EMPLOYEE);


SELECT MAX(SUM(BASIC)) as max_total_basic FROM EMPLOYEE GROUP BY DEPT_CODE;
SELECT MAX(AVG(BASIC)) as avg_total_basic FROM EMPLOYEE GROUP BY DEPT_CODE;
SELECT MAX(count(*)) as max_employees FROM EMPLOYEE GROUP BY DEPT_CODE;
DELETE FROM EMPLOYEE WHERE DEPT_CODE IS NULL;

DELETE FROM EMPLOYEE WHERE DESIG_CODE != ALL(SELECT DESIG_CODE FROM DESIGNATION);
DELETE FROM EMPLOYEE WHERE BASIC is null;

SELECT E.EMP_NAME,E.BASIC,E.DEPT_CODE 
FROM EMPLOYEE E
WHERE E.GENDER='F' AND E.BASIC > (SELECT AVG(BASIC) FROM EMPLOYEE WHERE E.DEPT_CODE=DEPT_CODE);


SELECT AVG(BASIC),DEPT_CODE FROM EMPLOYEE GROUP by DEPT_CODE;


SELECT EMP_NAME FROM EMPLOYEE WHERE GENDER='F' AND DESIG_CODE=(SELECT DESIG_CODE FROM DESIGNATION WHERE DESIG_DESC='MANAGER');



SELECT * 
FROM employee
; 


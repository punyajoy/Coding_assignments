SET SERVEROUTPUT ON

/*ACCEPT V PROMPT "Please enter your name: ";*/
/*
DECLARE
   V_LINE VARCHAR2(40);
   emp_name EMP.EMP_NAME%type;
   emp_code EMP.EMP_CODE%type:=1000;
   code CHAR(5);  
BEGIN
    code := :code;
   SELECT EMP_NAME,EMP_CODE INTO emp_name,emp_code FROM EMP WHERE EMP_CODE=code; 
   dbms_output.put_line
    ('Employee ' ||emp_name || ' has ' || emp_code ); 
EXCEPTION
WHEN NO_DATA_FOUND THEN
      DBMS_OUTPUT.PUT_LINE ('no employee with this code');


END; 
/
*/
/*
DECLARE
   
    name1 EMP.EMP_NAME%type;
    code EMP.EMP_CODE%type := '1000';
    COUNT1 INTEGER; 
    COUNT2 INTEGER;
    d_code EMP.DEPT_CODE%type;
    gen EMP.GENDER%type;
    add1  EMP.ADDRESS%type;
    base EMP.BASIC%type;
    pay EMP.PAY_GRADE%type;
    join1 EMP.JN_DT%type;
    invalid_id EXCEPTION;
    invalid_dept EXCEPTION;
BEGIN
   
    code := :code;
    d_code := :d_code;
    SELECT COUNT(*) INTO COUNT1 FROM EMP WHERE EMP_CODE=code; 
    SELECT COUNT(*) INTO COUNT2 FROM DEPT WHERE DEPT_CODE=d_code; 
     
       name1 := :name1;
       gen := :gen;
       DBMS_OUTPUT.PUT_LINE ('hello');
       
       add1 := :add1;
       base := :base;
   
     
       IF (base<6000) THEN
       pay:='C';
       ELSIF (base>6000 AND base<8000) THEN 
       pay :='B';
       ELSE 
       pay :='A';
       END IF;
       join1 := :join1;
       
    IF (COUNT1>0) THEN
      RAISE invalid_id;
      
    ELSIF (COUNT2 = 0) THEN
      RAISE invalid_dept;
      
    ELSE
      
      INSERT INTO EMP (EMP_CODE,EMP_NAME,DEPT_CODE, GENDER,ADDRESS,BASIC,PAY_GRADE,JN_DT) VALUES
      (code,name1,d_code,gen,add1,base,pay,join1);
    END IF;
    
    
EXCEPTION

WHEN invalid_id THEN
      DBMS_OUTPUT.PUT_LINE ('employee code_exist');
WHEN invalid_dept THEN
      DBMS_OUTPUT.PUT_LINE ('employee department does not exist');


END; 
/*/

DECLARE
   TYPE emps_array IS VARRAY(5) OF VARCHAR(20);
   
   
    
BEGIN
   
    
END; 
/


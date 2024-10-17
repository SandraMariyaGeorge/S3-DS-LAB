declare
  age number(3);
begin
  age:=&age;
  if age>=18 then
    dbms_output.put_line('ELIGIBLE FOR VOTING');
  else 
    dbms_output.put_line('NOT ELIGIBLE');
  end if;
end;
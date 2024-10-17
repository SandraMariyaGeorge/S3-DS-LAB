declare
  a number;
  b number;
  s number;
begin
  a:=&a;
  b:=&b;
  s:=a+b;
  dbms_output.put_line('sum of '||a||' + '||b||' = '||s);
end;
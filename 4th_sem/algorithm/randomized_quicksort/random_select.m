rs=load('H:\computerscience\c program\4th sem\random_select.txt');
for i=1:length(rs)-1
    x_axis(i)=i;
end
for i=1:length(rs)-1
    y_axis_1(i)=3*rs(1)/10;
end
for i=1:length(rs)-1
    y_axis_2(i)=7*rs(1)/10;
end


h=figure;
line(x_axis,y_axis_1,'LineWidth',3,'Color','r');
hold on
line(x_axis,rs(2:end),'Color','g');
hold on
line(x_axis,y_axis_2,'LineWidth',3,'Color','r');
legend('lower bound','selected index','upper bound');
xlabel('iterations');
ylabel('index');
saveas(h,sprintf('random_select.png'));


cuf=load('H:\computerscience\c program\4th sem\comparison_uniform_fixed.txt');
cur=load('H:\computerscience\c program\4th sem\comparison_uniform_random.txt');
cnf=load('H:\computerscience\c program\4th sem\comparison_normal_fixed.txt');
cnr=load('H:\computerscience\c program\4th sem\comparison_normal_random.txt');
p=load('H:\computerscience\c program\4th sem\pivot.txt');
k=1;
size=9;

%dividing into different  matrix according to no of elements


%%%%%%%%%%%%uniform%%%%%%%%%
for i=1:size
    for j=1:100
        a_uniform(i,j)=cur(k);
        k=k+1;
    end 
end
%calculating mean comparison

for i=1:size
    mean_uni(i)=mean(a_uniform(i,:));
end

%%%%%%%%normal%%%%%%%%%%%%%
k=1;
for i=1:size
    for j=1:100
        a_normal(i,j)=cnr(k);
        k=k+1;
    end 
end


for i=1:size
    mean_norm(i)=mean(a_normal(i,:));
end
%defining the x axis 

for i=1:100
    x_axis_2(i)=i;
end

for i=1:size
    x_axis(i)=i;
end
%================%


%dividing pivot into parts%
for i=1:100
    pivot_uniform(i)=p(i);
end

k=1;
for i=101:200
    pivot_normal(k)=p(i);
    k=k+1;
end
%===============%

p_vs_uniform(:,1)=pivot_uniform(1,:);
p_vs_uniform(:,2)=a_uniform(size,:);
p_vs_uniform=sortrows(p_vs_uniform,1);

p_vs_normal(:,1)=pivot_normal(1,:);
p_vs_normal(:,2)=a_normal(size,:);
p_vs_normal=sortrows(p_vs_normal,1);


%%%%figures=====
h=figure;
line(x_axis,mean_uni,'Color','r');
hold on
line(x_axis,mean_norm,'Color','g');
hold on
line(x_axis,cuf(1:size),'Color', 'b');
hold on
line(x_axis,cnf(1:size),'Color', 'c');
hold on
legend('random uniform','random normal','uniform fixed','normal fixed');
xlabel('no of elements in power of 2^i');
ylabel('comparison');
saveas(h,sprintf('sort.png'));

h=figure;
line(p_vs_uniform(:,1),p_vs_uniform(:,2),'Color','r');
hold on
line(p_vs_normal(:,1),p_vs_normal(:,2),'Color','g');
hold on
legend('uniform vs pivot','normal vs pivot');
xlabel('pivot position');
ylabel('comparison');
saveas(h,sprintf('pivot_vs_comparison.png'));

h=figure;
line(x_axis,mean_uni,'Color','r');
hold on
line(x_axis,cuf(1:size),'Color','g');
hold on
legend('random uniform','uniform fixed');
xlabel('no of elements in power of 2^i');
ylabel('comparison');
saveas(h,sprintf('sort_uniform.png'));

h=figure;
line(x_axis,mean_norm,'Color','r');
hold on
line(x_axis,cnf(1:size),'Color','g');
hold on
legend('random normal','uniform normal');
xlabel('no of elements in power of 2^i');
ylabel('comparison');
saveas(h,sprintf('sort_normal.png'));


h=figure;
line(x_axis_2,a_normal(size,:),'Color','r');
hold on
legend('random normal');
xlabel('iteration');
ylabel('comparison');
saveas(h,sprintf('comaparison_normal.png'));


h=figure;
line(x_axis_2,a_uniform(size,:),'Color','r');
hold on
legend('random uniform');
xlabel('iteration');
ylabel('comparison');
saveas(h,sprintf('comaparison_uniform.png'));







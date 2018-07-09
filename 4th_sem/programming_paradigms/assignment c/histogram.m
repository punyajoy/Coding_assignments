h=figure;
sort=load('normal.txt');
hist(sort);
hold on;
saveas(h,sprintf('normalhist.png'));
h=figure;
sort=load('uniform.txt');
hist(sort);
hold on;
saveas(h,sprintf('uniformhist.png'));


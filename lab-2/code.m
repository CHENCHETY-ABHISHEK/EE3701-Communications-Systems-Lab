close all;
clear all;
clc;
f1=load('h1.txt');
h1= transpose(f1);
%Magnitude Response for LPF-1
fvtool(h1,1);
title('Magnitude response plot for LPF1')

n1 = -19:19;
%Impulse response for LPF-1
stem(n1,h1,'LineStyle','-','MarkerFaceColor','blue','MarkerEdgeColor','black')
grid on;
xlabel('Samples (n)')
ylabel('Amplitude')
title('Impulse response plot for LPF1');

f2=load('h2.txt');
h2=transpose(f2);
%Magnitude Response for LPF-2
fvtool(h2,1);
title('Magnitude response plot for LPF2')

%Impulse response for LPF-1
stem(n1,h2,'LineStyle','-','MarkerFaceColor','green','MarkerEdgeColor','black')
grid on;
xlabel('Samples (n)')
ylabel('Amplitude')
title('Impulse response plot for LPF2');

f3=load('h3.txt');
h3=transpose(f3);
%Magnitude Response for BPF
fvtool(h3,1);
title('Magnitude response plot for BPF')

%Impulse response for BPF
stem(n1,h3,'LineStyle','-','MarkerFaceColor','red','MarkerEdgeColor','black')
grid on;
xlabel('Samples (n)')
ylabel('Amplitude')
title('Impulse response plot for BPF');
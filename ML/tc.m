function tc()

spam = dir('D:\ML\y.txt');
spam = {spam.name};
n_spam=size(spam,2);
fspam={};

for i=1:n_spam,
	temp=textread(spam{1,i},'%s');
	temp=regexprep(temp,'[^a-zA-Z]','');
	isemp=cellfun('isempty',temp);
	temp(isemp,:)=[];
  
	fspam=vertcat(fspam,temp);
end;
t_spam=size(fspam,1);



ham = dir('‪D:\ML\x.txt');
ham = {ham.name};
n_ham = size(ham,2);
fham={};


for i=1:n_ham,
	temp=textread(ham{1,i},'%s');
	temp=regexprep(temp,'[^a-zA-Z]','');
	isemp=cellfun('isempty',temp);
	temp(isemp,:)=[];
  
  
	fham=vertcat(fham,temp);
end;

t_ham=size(fham,1);


voca=vertcat(fspam,fham);
voca=unique(voca);
n_voca=size(voca,1);


ar_spam = cellfun(@(x) sum(ismember(fspam,x)),voca);
ar_ham = cellfun(@(x) sum(ismember(fham,x)),voca);

for i=1:n_voca,
ar_spam(i)= (ar_spam(i)+1)/(t_spam+n_voca);
ar_ham(i)= (ar_ham(i)+1)/(t_ham+n_voca);
end;

p_spam= n_spam/(n_spam+n_ham);
p_ham= n_ham/(n_spam+n_ham);

test = textread('test.txt','%s');
test=regexprep(test,'[^a-zA-Z]','');
temp=cellfun('isempty',test);
test(temp,:)=[];


n_test=size(test,1);
p_ts=p_spam;
p_th=p_ham;


[tm,tin]=ismember(test,voca);
for i=1:n_test,
	if(tm(i)>0),
	p_ts=p_ts*ar_spam(tin(i));
	p_th=p_th*ar_ham(tin(i));
	end;
end;


if(p_ts>p_th),
disp('document is spam');
else
disp('document is ham ');
end;
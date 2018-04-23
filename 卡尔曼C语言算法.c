// ��������˲�������Դ��40���������ѧ��Wiener��ǰ������ѧ�ң˧�ݧާ�ԧ���ӵ��˵��о�������
// ����ͳ��Ϊά���˲����ۡ���������˵��ά���˲������ȱ���Ǳ����õ����޹�ȥ�����ݣ���������ʵʱ����
// Ϊ�˿˷���һȱ�㣬60���Kalman��״̬�ռ�ģ�������˲����ۣ���������һ�׵��ƹ����㷨��
// ���˳�֮Ϊ�������˲����ۡ��������˲�������С�������Ϊ���Ƶ����׼����Ѱ��һ�׵��ƹ��Ƶ��㷨��
// �����˼���ǣ������ź���������״̬�ռ�ģ�ͣ�����ǰһʱ�̵ع���ֵ����ʱ�̵Ĺ۲�ֵ�����¶�״̬�����Ĺ��ƣ�
// �����ʱ�̵Ĺ���ֵ�����ʺ���ʵʱ����ͼ�������㡣
//
//
//
//��������ʱ��ϵͳ����ɢ״̬���Ǻ͹۲ⷽ��Ϊ��
//
//
//
//X(k) = F(k,k-1)��X(k-1)+T(k,k-1)��U(k-1)
//
//
//
//Y(k) = H(k)��X(k)+N(k)
//
//
//
//����
//
//
//
//X(k)��Y(k)�ֱ���kʱ�̵�״̬ʸ���͹۲�ʸ��
//
//
//
//F(k,k-1)Ϊ״̬ת�ƾ���
//
//
//
//U(k)Ϊkʱ�̶�̬����
//
//
//
//T(k,k-1)Ϊϵͳ���ƾ���
//
//
//
//H(k)Ϊkʱ�̹۲����
//
//
//
//N(k)Ϊkʱ�̹۲�����
//
//
//
//�򿨶����˲����㷨����Ϊ��
//
//
//
//
//
//Ԥ����X(k)^= F(k,k-1)��X(k-1) 
//
//����Ԥ����Э�������
//C(k)^=F(k,k-1)��C(k)��F(k,k-1)'+T(k,k-1)��Q(k)��T(k,k-1)'
//Q(k) = U(k)��U(k)' 
//
//���㿨�����������
//K(k) = C(k)^��H(k)'��[H(k)��C(k)^��H(k)'+R(k)]^(-1)
//R(k) = N(k)��N(k)' 
//
//���¹���
//X(k)~=X(k)^+K(k)��[Y(k)-H(k)��X(k)^] 
//
//������º����Э�������
//C(k)~ = [I-K(k)��H(k)]��C(k)^��[I-K(k)��H(k)]'+K(k)��R(k)��K(k)' 
//
//X(k+1) = X(k)~
//C(k+1) = C(k)~
//�ظ����ϲ��� 


//**************************************************************
//C���Դ��룺
//************************************************************
#include "stdlib.h"
#include "rinv.c"

int lman(n,m,k,f,q,r,h,y,x,p,g)
//int n,m,k;
//double f[],q[],r[],h[],y[],x[],p[],g[];
{ 
	int i,j,kk,ii,l,jj,js;
	double *e,*a,*b;
	e=malloc(m*m*sizeof(double));
  l=m;
  if (l<n) 
		l=n;
		
	a=malloc(l*l*sizeof(double));
	b=malloc(l*l*sizeof(double));
	
	for (i=0; i<=n-1; i++)
		for (j=0; j<=n-1; j++)
    { 
    	ii=i*l+j; a[ii]=0.0;
      for (kk=0; kk<=n-1; kk++)
        a[ii]=a[ii]+p[i*n+kk]*f[j*n+kk];
    }
    
  for (i=0; i<=n-1; i++)
		for (j=0; j<=n-1; j++)
    { 
    	ii=i*n+j; p[ii]=q[ii];
      for (kk=0; kk<=n-1; kk++)
        p[ii]=p[ii]+f[i*n+kk]*a[kk*l+j];
    }
    
	for (ii=2; ii<=k; ii++)
  { 
  	for (i=0; i<=n-1; i++)
      for (j=0; j<=m-1; j++)
      { 
      	jj=i*l+j; a[jj]=0.0;
        for (kk=0; kk<=n-1; kk++)
        a[jj]=a[jj]+p[i*n+kk]*h[j*n+kk];
      }
        
    for (i=0; i<=m-1; i++)
    	for (j=0; j<=m-1; j++)
      { 
      	jj=i*m+j; e[jj]=r[jj];
        for (kk=0; kk<=n-1; kk++)
          e[jj]=e[jj]+h[i*n+kk]*a[kk*l+j];
      }
      
    js=rinv(e,m);
    if (js==0) 
    { 
    	free(e); 
    	free(a); 
    	free(b); 
    	return(js);
    }
    
    for (i=0; i<=n-1; i++)
      for (j=0; j<=m-1; j++)
      { 
      	jj=i*m+j; g[jj]=0.0;
        for (kk=0; kk<=m-1; kk++)
          g[jj]=g[jj]+a[i*l+kk]*e[j*m+kk];
      }
      
    for (i=0; i<=n-1; i++)
    { 
    	jj=(ii-1)*n+i; x[jj]=0.0;
      for (j=0; j<=n-1; j++)
        x[jj]=x[jj]+f[i*n+j]*x[(ii-2)*n+j];
    }
        
    for (i=0; i<=m-1; i++)
    { 
    	jj=i*l; b[jj]=y[(ii-1)*m+i];
      for (j=0; j<=n-1; j++)
      	b[jj]=b[jj]-h[i*n+j]*x[(ii-1)*n+j];
    }
    
    for (i=0; i<=n-1; i++)
    { 
    	jj=(ii-1)*n+i;
      for (j=0; j<=m-1; j++)
        x[jj]=x[jj]+g[i*m+j]*b[j*l];
    }
    
    if (ii<k)
    { 
    	for (i=0; i<=n-1; i++)
        for (j=0; j<=n-1; j++)
        { 
        	jj=i*l+j; a[jj]=0.0;
          for (kk=0; kk<=m-1; kk++)
            a[jj]=a[jj]-g[i*m+kk]*h[kk*n+j];
          if (i==j) a[jj]=1.0+a[jj];
        }
            
        for (i=0; i<=n-1; i++)
         	for (j=0; j<=n-1; j++)
          { 
          	jj=i*l+j; b[jj]=0.0;
            for (kk=0; kk<=n-1; kk++)
            	b[jj]=b[jj]+a[i*l+kk]*p[kk*n+j];
          }
            
        for (i=0; i<=n-1; i++)
          for (j=0; j<=n-1; j++)
          { 
          	jj=i*l+j; a[jj]=0.0;
            for (kk=0; kk<=n-1; kk++)
              a[jj]=a[jj]+b[i*l+kk]*f[j*n+kk];
          }
          
        for (i=0; i<=n-1; i++)
          for (j=0; j<=n-1; j++)
          { 
          	jj=i*n+j; p[jj]=q[jj];
            for (kk=0; kk<=n-1; kk++)
              p[jj]=p[jj]+f[i*n+kk]*a[j*l+kk];
          }
        }
      }
      
    	free(e); 
    	free(a); 
    	free(b);
    	return(js);
  }

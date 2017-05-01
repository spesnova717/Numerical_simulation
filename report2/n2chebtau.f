      program n2chebychevtau
      implicit none
      integer i,j,n,k,m
      parameter(m=21)
      parameter(n=2)
      real*8 u(n+1),uk(n+1),uk_e(n/2+1),uk_o(n/2),c(0:n),Tkx(n+1)
      real*8 e(n/2+1,n/2+1),o(n/2,n/2),eo(n/2+1),oo(n/2)
      double precision dx, u_sum,x
      parameter(dx=2.0d0/(m-1))
            
      do 210 i=0,n
            if(i.eq.2)then
                  c(i)=2.0d0
            else if(i.lt.2)then
                  c(i)=0.0d0
            else if(i.gt.2)then
                  c(i)=1.0d0
            end if
210   end do
      
      do 110 j=1,int(n/2+1)
            do 120 i=1,int(n/2+1)
                  e(i,j)=0.0d0
                  eo(i)=0.0d0
                  if((mod(i,2).eq.1).and.(mod(j,2).eq.1)) then
                        o((i+1)/2,(j+1)/2)=0.0d0
                        oo((i+1)/2)=0.0d0
                  end if
120   	end do
110   end do

      do 130 j=1,int(n/2+1)
            e(1,j)=1.0d0
            if(mod(j,2).eq.1) then
                  o(1,(j+1)/2)=1.0d0
            end if
130   end do

      do 310 i=2,int(n/2+1)
            e(i,i-1)=c(int(2.0d0*i-2.0d0))/(4.0d0*
     &            (2.0d0*i-2.0d0)*(2.0d0*i-2.0d0-1.0d0))
            e(i,i)=-(1.0d0+1.0d0/
     &            (2.0d0*((2.0d0*i-2.0d0)**2.0d0-1.0d0)))
            if(i.lt.int(n/2+1))then
            e(i,i+1)=1.0d0/(4.0d0*(2.0d0*i-2.0d0)
     &            *((2.0d0*i-2.0d0)+1.0d0))
            end if
310   end do
      
      do 320 i=2,int(n/2)
            o(i,i-1)=c(int((2.0d0*(i+1.0d0)/
     &            2.0d0)-1.0d0))/(4.0d0*(2.0d0*i-2.0d0+1.0d0)
     &            *(2.0d0*i-2.0d0+1.0d0)-1.0d0)
            o(i,i)=-(1.0d0+1.0d0/
     &            (2.0d0*(2.0d0*i-2.0d0+1.0d0)
     &            **2.0d0-1.0d0))
            if(i.lt.int(n/2))then
            o(i,i+1)=1.0d0/(4.0d0
     &            *(2.0d0*i-2.0d0+1.0d0)
     &            *(2.0d0*i-2.0d0+1.0d0)+1.0d0)
            end if
320   end do

      eo(1)=1.0d0/2.0d0
      oo(1)=(1.0d0/2.0d0)

      call gauss_jordan(n/2+1,e,eo,uk_e)
      uk_o(1)=oo(1)

      do 410 k=1,int(n/2+1)
            uk(2*k-1)=uk_e(k)
410   end do
      do 420 k=1,int(n/2)
            uk(2*k)=uk_o(k)
420   end do
      u_sum=0.0d0
      write(10,*) -1.0d0,0.0d0
      do 300 i=2,m-1
            x=-1.0d0+dx*(i-1.0d0)
            Tkx(1)=1.0d0
            Tkx(2)=x
            do 400 j=3,n+1
                  Tkx(j)=2.0d0*x*Tkx(j-1)-Tkx(j-2)
400         end do

            do 100 k=1, n+1
                  u(k)=uk(k)*Tkx(k)
                  u_sum=u_sum+u(k)
100   	end do
      write(10,*) x,u_sum

      u_sum=0.0d0
300   end do
      write(10,*) 1.0d0,1.0d0

      stop
      end program n2chebychevtau

            
      subroutine gauss_jordan(n, a, b,c)

           INTEGER n
           INTEGER ipv, i, j
	   real*8 inv_pivot, temp
	   real*8 big
           real*8 a(n,n),b(n),c(n)
           INTEGER pivot_row, row(n)

           DO i=1,n
             c(i)=b(i)
           END DO

           DO 1200 ipv=1,n

              ! ---- 最大値探索 ---------------------------- !
              big=0.0d0
              DO 1210 i=ipv,n 
                 IF(abs(a(i,ipv)) .gt. big)THEN
                    big = abs(a(i,ipv))
                    pivot_row = i
                 END IF
1210           END DO
              IF(big .eq. 0.0d0)THEN
              return
              END IF
              row(ipv) = pivot_row

              ! ---- 行の入れ替え -------------------------- !
              IF(ipv .ne. pivot_row)THEN
                 DO 1220 i=1,n 
                    temp = a(ipv,i) 
                    a(ipv,i) = a(pivot_row,i) 
                    a(pivot_row,i) = temp 
1220              END DO
                 temp = c(ipv) 
                 c(ipv) = c(pivot_row) 
                 c(pivot_row) = temp 
              END IF

              ! ---- 対角成分=1(ピボット行の処理) ---------- !
              inv_pivot = 1.0d0/a(ipv,ipv) 
              a(ipv,ipv)=1.0d0 
              DO 1230 j=1,n 
                 a(ipv,j) = inv_pivot*a(ipv,j)
1230           END DO
              c(ipv) = inv_pivot*c(ipv) 

              ! ---- ピボット列=0(ピボット行以外の処理) ---- !
              DO 1240 i=1,n 
                 IF(i .ne. ipv)THEN
                    temp = a(i,ipv) 
                    a(i,ipv)=0.0d0 
                    DO 1250 j=1,n 
                       a(i,j) = a(i,j)-temp*a(ipv,j) 
1250                 END DO
                    c(i) = c(i)-temp*c(ipv) 
                 END IF
1240           END DO

1200        END DO

           return 
        end subroutine


FasdUAS 1.101.10   ��   ��    k             l     ����  Q       	��  r     
  
 I   
���� 
�� .JonsgClp****    ��� null��    �� ��
�� 
rtyp  m    ��
�� 
reco��    o      ���� 0 old   	 R      ������
�� .ascrerr ****      � ****��  ��  ��  ��  ��        l   " ����  O   "    I   !��  
�� .prcskprsnull���     ctxt  m       �    c  �� ��
�� 
faal  m    ��
�� eMdsKcmd��    m      �                                                                                  sevs  alis    �  Macintosh HD               �	K�H+   v�0System Events.app                                               y�����        ����  	                CoreServices    �	��      ��1     v�0 v�/ v�.  =Macintosh HD:System: Library: CoreServices: System Events.app   $  S y s t e m   E v e n t s . a p p    M a c i n t o s h   H D  -System/Library/CoreServices/System Events.app   / ��  ��  ��        l  # ( ����  I  # (�� ��
�� .sysoexecTEXT���     TEXT  m   # $   �   � e x p o r t   L C _ C T Y P E = U T F - 8 ;   p b p a s t e   |   / u s r / l o c a l / b i n / p y g m e n t i z e   - l   c s h a r p   - f   r t f   - O   s t y l e = m o n o k a i   |   p b c o p y   - P r e f e r   r t f��  ��  ��         l  ) 5 !���� ! O  ) 5 " # " I  - 4�� $ %
�� .prcskprsnull���     ctxt $ m   - . & & � ' '  v % �� (��
�� 
faal ( m   / 0��
�� eMdsKcmd��   # m   ) * ) )�                                                                                  sevs  alis    �  Macintosh HD               �	K�H+   v�0System Events.app                                               y�����        ����  	                CoreServices    �	��      ��1     v�0 v�/ v�.  =Macintosh HD:System: Library: CoreServices: System Events.app   $  S y s t e m   E v e n t s . a p p    M a c i n t o s h   H D  -System/Library/CoreServices/System Events.app   / ��  ��  ��      * + * l  6 ; ,���� , I  6 ;�� -��
�� .sysodelanull��� ��� nmbr - m   6 7 . . ?���������  ��  ��   +  /�� / l  < M 0���� 0 Q   < M 1 2�� 1 I  ? D�� 3��
�� .JonspClpnull���     **** 3 o   ? @���� 0 old  ��   2 R      ������
�� .ascrerr ****      � ****��  ��  ��  ��  ��  ��       �� 4 5 6��   4 ����
�� .aevtoappnull  �   � ****�� 0 old   5 �� 7���� 8 9��
�� .aevtoappnull  �   � **** 7 k     M : :   ; ;   < <   = =   > >  * ? ?  /����  ��  ��   8   9 ������������  ������ �� & .����
�� 
rtyp
�� 
reco
�� .JonsgClp****    ��� null�� 0 old  ��  ��  
�� 
faal
�� eMdsKcmd
�� .prcskprsnull���     ctxt
�� .sysoexecTEXT���     TEXT
�� .sysodelanull��� ��� nmbr
�� .JonspClpnull���     ****�� N *��l E�W X  hO� 	���l 
UO�j O� 	���l 
UO�j O 
�j W X  h 6 �� @ A
�� 
utf8 @ � B B� [ F a c t ] 
 p u b l i c   a s y n c   T a s k   w h e n _ I _ l o g i n _ I _ r e c e i v e _ a u t h _ t o k e n ( ) 
 { 
         / /   g i v e n 
         / /   a   L o g i n C o n t r o l l e r 
         v a r   s u t   =   n e w   B r o w s e r ( w i t h   = >   w i t h . M o d u l e < L o g i n C o n t r o l l e r > ( ) ) ; 
 
         / /   w h e n 
         / /   a   u s e r   l o g s   i n   w i t h   t h e   c o r r e c t   e m a i l   a n d   p a s s w o r d 
         v a r   a c t u a l   =   a w a i t   s u t . P o s t ( " / l o g i n " ,   " {   \ " e m a i l \ " :   \ " f o o @ c a l i b e r . c o m \ " ,   \ " p a s s w o r d \ " ,   \ " C a l i b e r R u l e s ! \ "   } " ) ; 
 
         / /   t h e n 
         A s s e r t . E q u a l ( " i t   s h o u l d   r e t u r n   2 0 0 " ,   H t t p S t a t u s C o d e . O K ,   a c t u a l . S t a t u s C o d e ) ; 
         A s s e r t . E q u a l ( " i t   s h o u l d   r e t u r n   a n   a u t h o r i z a t i o n   t o k e n  ,   a c t u a l . b o d y . c o n t a i n s ( " a u t h T o k e n " ) ) ; 
         A s s e r t . E q u a l ( " i t   s h o u l d   r e t u r n   a   r e f r e s h   t o k e n  ,   a c t u a l . b o d y . c o n t a i n s ( " r e f r e s h T o k e n " ) ) ; 
 } A �� C D
�� 
ut16 C � E E� [ F a c t ] 
 p u b l i c   a s y n c   T a s k   w h e n _ I _ l o g i n _ I _ r e c e i v e _ a u t h _ t o k e n ( ) 
 { 
         / /   g i v e n 
         / /   a   L o g i n C o n t r o l l e r 
         v a r   s u t   =   n e w   B r o w s e r ( w i t h   = >   w i t h . M o d u l e < L o g i n C o n t r o l l e r > ( ) ) ; 
 
         / /   w h e n 
         / /   a   u s e r   l o g s   i n   w i t h   t h e   c o r r e c t   e m a i l   a n d   p a s s w o r d 
         v a r   a c t u a l   =   a w a i t   s u t . P o s t ( " / l o g i n " ,   " {   \ " e m a i l \ " :   \ " f o o @ c a l i b e r . c o m \ " ,   \ " p a s s w o r d \ " ,   \ " C a l i b e r R u l e s ! \ "   } " ) ; 
 
         / /   t h e n 
         A s s e r t . E q u a l ( " i t   s h o u l d   r e t u r n   2 0 0 " ,   H t t p S t a t u s C o d e . O K ,   a c t u a l . S t a t u s C o d e ) ; 
         A s s e r t . E q u a l ( " i t   s h o u l d   r e t u r n   a n   a u t h o r i z a t i o n   t o k e n  ,   a c t u a l . b o d y . c o n t a i n s ( " a u t h T o k e n " ) ) ; 
         A s s e r t . E q u a l ( " i t   s h o u l d   r e t u r n   a   r e f r e s h   t o k e n  ,   a c t u a l . b o d y . c o n t a i n s ( " r e f r e s h T o k e n " ) ) ; 
 } D �� F G
�� 
TEXT F � H H� [ F a c t ]  p u b l i c   a s y n c   T a s k   w h e n _ I _ l o g i n _ I _ r e c e i v e _ a u t h _ t o k e n ( )  {          / /   g i v e n          / /   a   L o g i n C o n t r o l l e r          v a r   s u t   =   n e w   B r o w s e r ( w i t h   = >   w i t h . M o d u l e < L o g i n C o n t r o l l e r > ( ) ) ;           / /   w h e n          / /   a   u s e r   l o g s   i n   w i t h   t h e   c o r r e c t   e m a i l   a n d   p a s s w o r d          v a r   a c t u a l   =   a w a i t   s u t . P o s t ( " / l o g i n " ,   " {   \ " e m a i l \ " :   \ " f o o @ c a l i b e r . c o m \ " ,   \ " p a s s w o r d \ " ,   \ " C a l i b e r R u l e s ! \ "   } " ) ;           / /   t h e n          A s s e r t . E q u a l ( " i t   s h o u l d   r e t u r n   2 0 0 " ,   H t t p S t a t u s C o d e . O K ,   a c t u a l . S t a t u s C o d e ) ;          A s s e r t . E q u a l ( " i t   s h o u l d   r e t u r n   a n   a u t h o r i z a t i o n   t o k e n  ,   a c t u a l . b o d y . c o n t a i n s ( " a u t h T o k e n " ) ) ;          A s s e r t . E q u a l ( " i t   s h o u l d   r e t u r n   a   r e f r e s h   t o k e n  ,   a c t u a l . b o d y . c o n t a i n s ( " r e f r e s h T o k e n " ) ) ;  } G �� I��
�� 
utxt I � J J� [ F a c t ]  p u b l i c   a s y n c   T a s k   w h e n _ I _ l o g i n _ I _ r e c e i v e _ a u t h _ t o k e n ( )  {          / /   g i v e n          / /   a   L o g i n C o n t r o l l e r          v a r   s u t   =   n e w   B r o w s e r ( w i t h   = >   w i t h . M o d u l e < L o g i n C o n t r o l l e r > ( ) ) ;           / /   w h e n          / /   a   u s e r   l o g s   i n   w i t h   t h e   c o r r e c t   e m a i l   a n d   p a s s w o r d          v a r   a c t u a l   =   a w a i t   s u t . P o s t ( " / l o g i n " ,   " {   \ " e m a i l \ " :   \ " f o o @ c a l i b e r . c o m \ " ,   \ " p a s s w o r d \ " ,   \ " C a l i b e r R u l e s ! \ "   } " ) ;           / /   t h e n          A s s e r t . E q u a l ( " i t   s h o u l d   r e t u r n   2 0 0 " ,   H t t p S t a t u s C o d e . O K ,   a c t u a l . S t a t u s C o d e ) ;          A s s e r t . E q u a l ( " i t   s h o u l d   r e t u r n   a n   a u t h o r i z a t i o n   t o k e n  ,   a c t u a l . b o d y . c o n t a i n s ( " a u t h T o k e n " ) ) ;          A s s e r t . E q u a l ( " i t   s h o u l d   r e t u r n   a   r e f r e s h   t o k e n  ,   a c t u a l . b o d y . c o n t a i n s ( " r e f r e s h T o k e n " ) ) ;  }��  ascr  ��ޭ
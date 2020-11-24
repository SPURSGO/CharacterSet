# 字符集的那些事

### 一：字符集发展史，常见字符集及其编码规则
1. ASCII —— American Standard Code for Information Interchange: 美国信息交换标准代码
   ASCII第一次以规范标准的形式发表是在1967年，最后一次更新则是在1986年，到目前为止共定义了128个字符。这是最早出现的最原始的字符集。 其内容如下：<br>

|DEC|	OCT	|HEX|	BIN	|缩写/符号	|描述|
|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|0	|000	|00	|00000000	|NUL	|Null char (空字符)
|1	|001	|01	|00000001	|SOH	|Start of Heading (标题开始)
|2	|002	|02	|00000010	|STX	|Start of Text (正文开始)
|3	|003	|03	|00000011	|ETX	|End of Text (正文结束)
|4	|004	|04	|00000100	|EOT	|End of Transmission (传输结束)
|5	|005	|05	|00000101	|ENQ	|Enquiry (请求)
|6	|006	|06	|00000110	|ACK	|Acknowledgment (收到通知)
|7	|007	|07	|00000111	|BEL	|Bell (响铃)
|8	|010	|08	|00001000	|BS	|Back Space (退格)
|9	|011	|09	|00001001	|HT	|Horizontal Tab (水平制表符)
|10	|012	|0A	|00001010	|LF	|Line Feed (换行键)
|11	|013	|0B	|00001011	|VT	|Vertical Tab (垂直制表符)
|12	|014	|0C	|00001100	|FF	|Form Feed (换页键)
|13	|015	|0D	|00001101	|CR	|Carriage Return (回车键)
|14	|016	|0E	|00001110	|SO	|Shift Out / X-On (不用切换)
|15	|017	|0F	|00001111	|SI	|Shift In / X-Off (启用切换)
|16	|020	|10	|00010000	|DLE		|Data Line Escape (数据链路转义)
|17	|021	|11	|00010001	|DC1		|Device Control 1 (设备控制1)
|18	|022	|12	|00010010	|DC2		|Device Control 2 (设备控制2)
|19	|023	|13	|00010011	|DC3		|Device Control 3 (设备控制3)
|20	|024	|14	|00010100	|DC4		|Device Control 4 (设备控制4)
|21	|025	|15	|00010101	|NAK		|Negative Acknowledgement (拒绝接收)
|22	|026	|16	|00010110	|SYN		|Synchronous Idle (同步空闲)
|23	|027	|17	|00010111	|ETB		|End of Transmit Block (传输块结束)
|24	|030	|18	|00011000	|CAN		|Cancel (取消)
|25	|031	|19	|00011001	|EM	 	  |End of Medium (介质中断)
|26	|032	|1A	|00011010	|SUB		|Substitute (替补)
|27	|033	|1B	|00011011	|ESC		|Escape (溢出)
|28	|034	|1C	|00011100	|FS		|File Separator (文件分割符)
|29	|035	|1D	|00011101	|GS		|Group Separator (分组符)
|30	|036	|1E	|00011110	|RS		|Record Separator (记录分离符)
|31	|037	|1F	|00011111	|US	 	|Unit Separator (单元分隔符)
|32	|040	|20	|00100000	| 		|Space (空格)
|33	|041	|21	|00100001	|!		|Exclamation mark
|34	|042	|22	|00100010	|"		|Double quotes
|35	|043	|23	|00100011	|#		|Number
|36	|044	|24	|00100100	|$		|Dollar
|37	|045	|25	|00100101	|%		|Procenttecken
|38	|046	|26	|00100110	|&		|Ampersand
|39	|047	|27	|00100111	|'		|Single quote
|40	|050	|28	|00101000	|(		|Open parenthesis
|41	|051	|29	|00101001	|)		|Close parenthesis
|42	|052	|2A	|00101010	|*		|Asterisk
|43	|053	|2B	|00101011	|+		|Plus
|44	|054	|2C	|00101100	|,		|Comma
|45	|055	|2D	|00101101	|-		|Hyphen
|46	|056	|2E	|00101110	|.		|Period, dot or full stop
|47	|057	|2F	|00101111	|/		|Slash or divide
|48	|060	|30	|00110000	|0		|Zero
|49	|061	|31	|00110001	|1		|One
|50	|062	|32	|00110010	|2		|Two
|51	|063	|33	|00110011	|3		|Three
|52	|064	|34	|00110100	|4		|Four
|53	|065	|35	|00110101	|5		|Five
|54	|066	|36	|00110110	|6		|Six
|55	|067	|37	|00110111	|7		|Seven
|56	|070	|38	|00111000	|8		|Eight
|57	|071	|39	|00111001	|9		|Nine
|58	|072	|3A	|00111010	|:		|Colon
|59	|073	|3B	|00111011	|;		|Semicolon
|60	|074	|3C	|00111100	|<		|Less than
|61	|075	|3D	|00111101	|=		|Equals
|62	|076	|3E	|00111110	|>		|Greater than
|63	|077	|3F	|00111111	|?		|Question mark
|64	|100	|40	|01000000	|@		|At symbol
|65	|101	|41	|01000001	|A		|Uppercase A
|66	|102	|42	|01000010	|B		|Uppercase B
|67	|103	|43	|01000011	|C		|Uppercase C
|68	|104	|44	|01000100	|D		|Uppercase D
|69	|105	|45	|01000101	|E		|Uppercase E
|70	|106	|46	|01000110	|F		|Uppercase F
|71	|107	|47	|01000111	|G		|Uppercase G
|72	|110	|48	|01001000	|H		|Uppercase H
|73	|111	|49	|01001001	|I		|Uppercase I
|74	|112	|4A	|01001010	|J		|Uppercase J
|75	|113	|4B	|01001011	|K		|Uppercase K
|76	|114	|4C	|01001100	|L		|Uppercase L
|77	|115	|4D	|01001101	|M		|Uppercase M
|78	|116	|4E	|01001110	|N		|Uppercase N
|79	|117	|4F	|01001111	|O		|Uppercase O
|80	|120	|50	|01010000	|P		|Uppercase P
|81	|121	|51	|01010001	|Q		|Uppercase Q
|82	|122	|52	|01010010	|R		|Uppercase R
|83	|123	|53	|01010011	|S		|Uppercase S
|84	|124	|54	|01010100	|T		|Uppercase T
|85	|125	|55	|01010101	|U		|Uppercase U
|86	|126	|56	|01010110	|V		|Uppercase V
|87	|127	|57	|01010111	|W		|Uppercase W
|88	|130	|58	|01011000	|X		|Uppercase X
|89	|131	|59	|01011001	|Y		|Uppercase Y
|90	|132	|5A	|01011010	|Z		|Uppercase Z
|91	|133	|5B	|01011011	|[		|Opening bracket
|92	|134	|5C	|01011100	|\		|Backslash
|93	|135	|5D	|01011101	|]		|Closing bracket
|94	|136	|5E	|01011110	|^		|Caret - circumflex
|95	|137	|5F	|01011111	|_		|Underscore
|96	|140	|60	|01100000	|`		|Grave accent
|97	|141	|61	|01100001	|a		|Lowercase a
|98	|142	|62	|01100010	|b		|Lowercase b
|99	|143	|63	|01100011	|c		|Lowercase c
|100	|144	|64	|01100100	|d		|Lowercase d
|101	|145	|65	|01100101	|e		|Lowercase e
|102	|146	|66	|01100110	|f		|Lowercase f
|103	|147	|67	|01100111	|g		|Lowercase g
|104	|150	|68	|01101000	|h		|Lowercase h
|105	|151	|69	|01101001	|i		|Lowercase i
|106	|152	|6A	|01101010	|j		|Lowercase j
|107	|153	|6B	|01101011	|k		|Lowercase k
|108	|154	|6C	|01101100	|l		|Lowercase l
|109	|155	|6D	|01101101	|m		|Lowercase m
|110	|156	|6E	|01101110	|n		|Lowercase n
|111	|157	|6F	|01101111	|o		|Lowercase o
|112	|160	|70	|01110000	|p		|Lowercase p
|113	|161	|71	|01110001	|q		|Lowercase q
|114	|162	|72	|01110010	|r		|Lowercase r
|115	|163	|73	|01110011	|s		|Lowercase s
|116	|164	|74	|01110100	|t		|Lowercase t
|117	|165	|75	|01110101	|u		|Lowercase u
|118	|166	|76	|01110110	|v		|Lowercase v
|119	|167	|77	|01110111	|w		|Lowercase w
|120	|170	|78	|01111000	|x		|Lowercase x
|121	|171	|79	|01111001	|y		|Lowercase y
|122	|172	|7A	|01111010	|z		|Lowercase z
|123	|173	|7B	|01111011	|{		|Opening brace
|124	|174	|7C	|01111100	||		|Vertical bar
|125	|175	|7D	|01111101	|}		|Closing brace
|126	|176	|7E	|01111110	|~		|Equivalency sign (tilde)
|127	|177	|7F	|01111111	|	  	|Delete


> ANSI 字符集：所谓ANSI字符集并不是指某一种特殊的字符集。它实际上是指基于ASCII扩展而来的字符集的总称。
就比如中国的GB2312(GBK、GB18030)和BIG5，日本的Shift-JIS，以及其他国家定义的ASCII扩展字符集。

<br>

2. GB2312
   《信息交换用汉字编码字符集》是由中国国家标准总局1980年发布，1981年5月1日开始实施的一套国家标准，标准号是GB 2312—1980。
   GB2312标准共收录6763个汉字，其中一级汉字3755个，二级汉字3008个；同时，GB2312收录了包括拉丁字母、希腊字母、日文平假名及片假名字母、俄语西里尔字母在内的682个全角字符。
   GB 2312的出现，基本满足了汉字的计算机处理需要，它所收录的汉字已经覆盖中国大陆99.75%的使用频率。
   但是对于人名、古汉语等方面出现的罕用字，GB 2312不能处理，这导致了后来GBK及GB 18030汉字字符集的出现。
> 分区表示：
GB2312对所收汉字进行了“分区”处理，每区含有94个汉字/符号。这种表示方式也称为区位码。
01-09区为特殊符号。
16-55区为一级汉字，按拼音排序。
56-87区为二级汉字，按部首/笔画排序。
10-15区及88-94区则未有编码。
举例来说，“啊”字是GB2312之中的第一个汉字，它的区位码就是1601。

> 双字节编码
GB2312规定对收录的每个字符采用两个字节表示，第一个字节为“高字节”，对应94个区；第二个字节为“低字节”，对应94个位。所以它的区位码范围是：0101－9494(十进制表示)。区号和位号分别加上0xA0就是GB2312编码。例如最后一个码位是9494，区号和位号分别转换成十六进制是5E5E，0x5E+0xA0＝0xFE，所以该码位的GB2312编码是FEFE。
GB2312编码范围：A1A1－FEFE，其中汉字的编码范围为B0A1-F7FE，第一字节0xB0-0xF7（对应区号：16－87），第二个字节0xA1-0xFE（对应位号：01－94）。<br>
GB2312具体字符的编码值及编码规则可查看[此工具网站](https://www.qqxiuzi.cn/zh/hanzi-gb2312-bianma.php)。

<br>

3. GBK(采用单双字节变长编码)
   GBK编码，是对GB2312编码的扩展，因此完全兼容GB2312-80标准。GBK编码依然采用双字节编码方案，其编码范围：8140－FEFE，剔除xx7F码位，共23940个码位。共收录汉字和图形符号21886个，其中汉字（包括部首和构件）21003个，图形符号883个。GBK编码支持国际标准ISO/IEC10646-1和国家标准GB13000-1中的全部中日韩(CJK)汉字，并包含了BIG5编码中的所有汉字。GBK编码方案于1995年12月15日正式发布，这一版的GBK规范为1.0版。
> 码位分配及顺序：
GBK 亦采用双字节表示，总体编码范围为 8140-FEFE，首字节在 81-FE 之间，尾字节在 40-FE 之间，剔除 xx7F 一条线。总计 23940 个码位，共收入 21886 个汉字和图形符号，其中汉字（包括部首和构件）21003 个，图形符号 883 个。<br>
全部编码分为三大部分：
一、汉字区。包括：
a. GB 2312 汉字区。即 GBK/2: B0A1-F7FE。收录 GB 2312 汉字 6763 个，按原顺序排列。
b. GB 13000.1 扩充汉字区。包括：
(1) GBK/3: 8140-A0FE。收录 GB 13000.1 中的 CJK 汉字 6080 个。
(2) GBK/4: AA40-FEA0。收录 CJK 汉字和增补的汉字 8160 个。CJK 汉字在前，按 UCS 代码大小排列；增补的汉字（包括部首和构件）在后，按《康熙字典》的页码/字位排列。
(3) 汉字“〇”安排在图形符号区GBK/5：A996。<br>
二、图形符号区。包括：
a. GB 2312 非汉字符号区。即 GBK/1: A1A1-A9FE。其中除 GB 2312 的符号外，还有 10 个小写罗马数字和 GB 12345 增补的符号。计符号 717 个。
b. GB 13000.1 扩充非汉字区。即 GBK/5: A840-A9A0。BIG-5 非汉字符号、结构符和“〇”排列在此区。计符号 166 个。<br>
三、用户自定义区：分为(1)(2)(3)三个小区。
(1) AAA1-AFFE，码位 564 个。
(2) F8A1-FEFE，码位 658 个。
(3) A140-A7A0，码位 672 个。
第(3)区尽管对用户开放，但限制使用，因为不排除未来在此区域增补新字符的可能性。<br>
GBK具体字符的编码值及编码规则可查看[此工具网站](https://www.qqxiuzi.cn/zh/hanzi-gbk-bianma.php)。

<br>


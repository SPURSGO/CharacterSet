# 字符集的那些事

### 一：字符集发展史，常见字符集及其编码规则
1. <b>ASCII</b> —— American Standard Code for Information Interchange: 美国信息交换标准代码
   ASCII第一次以规范标准的形式发表是在<b>1967年</b>，最后一次更新则是在<b>1986年</b>，到目前为止共定义了128个字符。这是最早出现的最原始的字符集。 其内容可参见文末。

<br>

> <b>ANSI 字符集</b>：所谓ANSI字符集并不是指某一种特殊的字符集。它实际上是指ASCII字符集和基于ASCII扩展而来的字符集的总称。
就比如中国的GB2312(GBK、GB18030)和BIG5，日本的Shift-JIS，以及其他国家定义的ASCII扩展字符集。

<br>

2. <b>GB2312</b><br>
   《信息交换用汉字编码字符集》是由中国国家标准总局<b>1980年</b>发布，<b>1981年5月1日</b>开始实施的一套国家标准，标准号是GB 2312—1980。<br>
   GB2312标准共收录6763个汉字，其中一级汉字3755个，二级汉字3008个；同时，GB2312收录了包括拉丁字母、希腊字母、日文平假名及片假名字母、俄语西里尔字母在内的682个全角字符。<br>
   GB2312的出现，基本满足了汉字的计算机处理需要，它所收录的汉字已经覆盖中国大陆99.75%的使用频率。
   但是对于人名、古汉语等方面出现的罕用字，GB2312不能处理，这导致了后来GBK及GB18030汉字字符集的出现。<br>
> 分区表示：<br>
GB2312对所收汉字进行了“分区”处理，每区含有94个汉字/符号。这种表示方式也称为区位码。<br>
01-09区为特殊符号。<br>
16-55区为一级汉字，按拼音排序。<br>
56-87区为二级汉字，按部首/笔画排序。<br>
10-15区及88-94区则未有编码。<br>
举例来说，“啊”字是GB2312之中的第一个汉字，它的区位码就是1601。<br>

> <b>双字节编码</b>：<br>
GB2312规定对收录的每个字符采用两个字节表示，第一个字节为“高字节”，对应94个区；第二个字节为“低字节”，对应94个位。所以它的区位码范围是：0101－9494(十进制表示)。<br>
区号和位号分别加上0xA0就是GB2312编码。<br>
例如：“啊”的区位码是0x1001, 区号和位号分别加上0xA0，得到的0xB0A1就是其GB2312编码。<br><br>
<b>GB2312编码范围：A1A1－FEFE</b><br>
其中汉字的编码范围为B0A1-F7FE，第一字节0xB0-0xF7（对应区号：16－87），第二个字节0xA1-0xFE（对应位号：01－94）。<br>
GB2312具体字符的编码值及编码规则可查看[此工具网站](https://www.qqxiuzi.cn/zh/hanzi-gb2312-bianma.php)。

<br>

3. <b>Unicode</b><br>
   在全世界出现了很多不同的ANSI字符集之后，很多国家都在为自己的文字编码，并且互不想通，这就造成不同的语言字符编码值相同却代表不同的符号（例如：韩文编码EUC-KR中“한국어”的编码值正好是汉字编码GBK中的“茄惫绢”）。因此，同一份文档，拷贝至不同语言环境(Locale)的机器，就可能成了乱码。所以，全球字符大一统的需求应运而生。<br>
   <br>
   首先需要明确一点的是Unicode并不是一种字符编码方式，它仅仅是一个字符集。但是这个字符集特别的大，大到足以容纳全世界所有的字符。从而可以让全世界都统一使用同一套字符集，并且可以让全世界都使用相同的编码格式(UTF-8/16/32)，从而解决乱码的问题。<br>
<br>

> 推进全球字符集大一统的两大组织：<br>
    (1) 国际标准化组织（ISO），他们于<b>1984年</b>创建ISO/IEC JTC1/SC2/WG2工作组，试图制定一份“通用字符集”（Universal Character Set，简称UCS），并最终制定了<b>ISO 10646标准</b>。<br>
    (2) 统一码联盟，他们由Xerox、Apple等软件制造商于<b>1988年</b>组成，并且开发了<b>Unicode标准</b>（The Unicode Standard，这个前缀Uni 代表了 Universal，Unique， and Uniform）。<br><br>
    <b>1991年</b>前后，两个项目的参与者都认识到，世界不需要两个不兼容的字符集。于是，它们开始合并双方的工作成果，并为创立一个单一编码表而协同工作。<b>从Unicode 2.0开始，Unicode采用了与ISO 10646-1相同的字库和字码；ISO也承诺，ISO 10646将不会给超出U+10FFFF的字符编号，以使得两者保持一致</b>。两个项目仍都独立存在，并独立地公布各自的标准。不过由于Unicode这一名字比较好记，因而它使用更为广泛。
<br>

##### 与Unicode相关的一系列重要概念
> Code Point、Plane、BMP：<br>
    在实际编码(考虑存储)之前先给每个穷举到的字符编号，即是<b>Code Point(码位)</b>，把它当做是数学概念，和用几个字节存储无关，只要发布Unicode 的标准化组织（ISO 和 统一码联盟）愿意，将新出现的字符继续向后编号就可以了，既然是数学序号，那就没有什么不够用的问题。<br><br>
    在编号的过程中，标准化组织还将用到的数字编号(码位)进行了分区操作。从而引出了<b>Plane(平面)</b>的概念。即将256×256=65536个码位作为一个平面(一个二维平面，长宽均为256个编号)。<br><br>
    此外，在对全球字符编号时有一些原则，就是将越常用的字符越靠前。所以，前65536个字符所构成的第一个Plane(平面)，这个平面就叫做<b>基本多文种平面（BMP - Basic Multilingual Plane）</b>。而大于BMP最大值的码位所构成的平面，就被称作<b>辅助平面</b>。并且ISO和统一码联盟为了兼容问题，协商确定<b>最多使用16个辅助平面</b>。<br><br>
    只为最常用的字符编号肯定是不行的，因为在某些特殊的场景之下，我们会用到那些不常用的字符。所以那些相对不常用的字符就被编号于辅助平面内。以下是辅助平面中16个平面的名称和编码范围：<br>

|平面	|编码范围	|中文名称|英文名称|
|:----:|:----:|:----:|:----:|
|0号平面	|[U+0000 - U+FFFF](https://www.qqxiuzi.cn/zh/unicode-zifu.php?plane=0)	|基本多文种平面	|Basic Multilingual Plane,简称BMP|
|1号平面	|[U+10000 - U+1FFFF](https://www.qqxiuzi.cn/zh/unicode-zifu.php?plane=1)	|多文种补充平面	|Supplementary Multilingual Plane,简称SMP|
|2号平面	|[U+20000 - U+2FFFF](https://www.qqxiuzi.cn/zh/unicode-zifu.php?plane=2)	|表意文字补充平面	|Supplementary Ideographic Plane,简称SIP|
|3号平面	|[U+30000 - U+3FFFF](https://www.qqxiuzi.cn/zh/unicode-zifu.php?plane=3)|	表意文字第三平面	|Tertiary Ideographic Plane,简称TIP|
|4～13号平面	|[U+40000 - U+DFFFF](https://www.qqxiuzi.cn/zh/unicode-zifu.php?plane=4)	|（尚未使用）	| | 
|14号平面	|[U+E0000 - U+EFFFF](https://www.qqxiuzi.cn/zh/unicode-zifu.php?plane=14)	|特别用途补充平面	|Supplementary Special-purpose Plane,简称SSP|
|15号平面	|[U+F0000 - U+FFFFF](https://www.qqxiuzi.cn/zh/unicode-zifu.php?plane=15)	|保留作为私人使用区（A区）|	Private Use Area-A,简称PUA-A|
|16号平面	|[U+100000 - U+10FFFF](https://www.qqxiuzi.cn/zh/unicode-zifu.php?plane=16)	|保留作为私人使用区（B区） | Private Use Area-B,简称PUA-B|
<br>
<br>

> <b>UTF-16编码规则</b>(关于代理对的概念后续再补上)：<br>
> 前面提到过：Unicode码位分为17个平面(1个BMP+16个辅助平面)。<br>
> 在<b>BMP内</b>的字符，UTF-16直接使用Unicode码位作为其编码值。
> 如：“汉”在Unicode中的码位为6C49，所以UTF-16编码也为496C(该值为大端表示，小端为6C49)。<br><br>
> 在<b>辅助平面内</b>的字符,按照以下规则编码：
> 用它们在Unicode中码位<b>减去0x10000</b>获得一个数字，该数字的<b>前10位(bits)加上0xD800</b>，就得到UTF-16四字节编码中的<b>前两个字节</b>；该数字的<b>后10位(bits)加上0xDC00</b>，就得到UTF-16四字节编码中的<b>后两个字节</b>。<br>
> 如：“𪺫(nǎi)”的码位为2AEAB，减去0x10000得到1AEAB（二进制值为0001 1010 1110 1010 1011），前10位加上D800得到D86B，后10位加上DC00得到DEAB。所以“𪺫”的UTF-16的编码值为D86BDEAB（该值为大端表示，小端为6BD8ABDE）。<br>
> 
<br>

> <b>UTF-8编码规则：</b><br>
> (1) 对于ASCII码中的符号，使用单字节编码，其编码值与ASCII值相同。其中ASCII值的范围为0~0x7F，所有编码的二进制值中第一位为0（这个正好可以用来区分单字节编码和多字节编码）。<br>
(2) 其它字符用多个字节来编码（假设用N个字节,N>1），<b>多字节编码需满足：第一个字节的前N位都为1，第N+1位为0，后面N-1 个字节的前两位都为10，这N个字节中其余位全部用来存储Unicode中的码位值</b>。如下表：

|字节数(N)	|Unicode码位 | UTF-8编码 |
|:----:|:----:|:----:|
|1	|000000-00007F	|0xxxxxxx|
|2	|000080-0007FF	|110xxxxx 10xxxxxx|
|3	|000800-00FFFF	|1110xxxx 10xxxxxx 10xxxxxx|
|4	|010000-10FFFF	|11110xxx 10xxxxxx 10xxxxxx 10xxxxxx|

> 如：“汉”的 Unicode 码位是 0x6c49（110 1100 0100 1001），通过上面的对照表得知，0x00 6c49 位于第三行的范围，那么得出其格式为 1110xxxx 10xxxxxx 10xxxxxx。接着，从“汉”的二进制数最后一位开始，从后向前依次填充对应格式中的 x，多出的 x 用 0 补上。这样，就得到了“汉”的 UTF-8 编码为 11100110 10110001 10001001，转换成十六进制就是 0xE6 0xB1 0x89。
<br>

 ###### <b>UTF-8 BOM</b><br>
 UTF-8 BOM又叫UTF-8 签名，UTF-8不需要BOM来表明字节顺序，但可以用BOM来表明编码方式。当文本程序读取到以 EF BB BF开头的字节流时，就知道这是UTF-8编码了。Windows就是使用BOM来标记文本文件的编码方式的。<br>
> "ZERO WIDTH NO-BREAK SPACE"字符(BOM)的Unicode码位为FEFF，所以对应的UTF-8编码为 EF BB BF。根据Unicode标准，不建议使用UTF-8文件的BOM。

<br>
<br>

> <b>UTF-32编码规则：</b><br>
   其编码规则很简单,。由于UTF-32采用定长4字节存储每一个字符，所以它足以容纳Unicode字符集中的所有字符。 从而它的编码就可以直接使用Unicode字符码位。<br>
   比如英文字符串“ABC”，这三个字符的UTF-32编码序列为：00 00 00 41 00 00 00 42 00 00 00 43；当然，因为一个字符需要几个字节来保存，所以是需要BOM的。<br>
   非BMP字符在大部分文件中很罕见，以致于它们通常被认为不存在占用空间大小的讨论，使得UTF-32通常会是其它编码的二到四倍。虽然每一个码位使用定长4字节看似方便，但是实际上它并不如其它Unicode编码使用得广泛。

<br>
<br>



1. <b>GBK(采用单双字节变长编码)</b><br>
   GBK编码，是对GB2312编码的扩展，因此完全兼容GB2312-80标准。<br>
   GBK编码依然采用双字节编码方案，其编码范围：8140－FEFE，剔除xx7F码位，共23940个码位。共收录汉字和图形符号21886个，其中汉字（包括部首和构件）21003个，图形符号883个。<br>
   GBK编码支持国际标准ISO/IEC10646-1和国家标准GB13000-1中的全部中日韩(CJK)汉字，并包含了BIG5编码中的所有汉字。<br>
   GBK编码方案于<b>1995年12月15日</b>正式发布，这一版的GBK规范为1.0版。
> 码位分配及顺序：<br>
GBK 亦采用双字节表示，总体编码范围为 8140-FEFE，首字节在 81-FE 之间，尾字节在 40-FE 之间，剔除 xx7F 一条线。总计 23940 个码位，共收入 21886 个汉字和图形符号，其中汉字（包括部首和构件）21003 个，图形符号 883 个。<br>
全部编码分为三大部分：<br>
一、汉字区。包括：<br>
a. GB 2312 汉字区。即 GBK/2: B0A1-F7FE。收录 GB 2312 汉字 6763 个，按原顺序排列。<br>
b. GB 13000.1 扩充汉字区。包括：<br>
(1) GBK/3: 8140-A0FE。收录 GB 13000.1 中的 CJK 汉字 6080 个。<br>
(2) GBK/4: AA40-FEA0。收录 CJK 汉字和增补的汉字 8160 个。CJK 汉字在前，按 UCS 代码大小排列；增补的汉字（包括部首和构件）在后，按《康熙字典》的页码/字位排列。<br>
(3) 汉字“〇”安排在图形符号区GBK/5：A996。<br>
二、图形符号区。包括：<br>
a. GB 2312 非汉字符号区。即 GBK/1: A1A1-A9FE。其中除 GB 2312 的符号外，还有 10 个小写罗马数字和 GB 12345 增补的符号。计符号 717 个。<br>
b. GB 13000.1 扩充非汉字区。即 GBK/5: A840-A9A0。BIG-5 非汉字符号、结构符和“〇”排列在此区。计符号 166 个。<br>
三、用户自定义区：分为(1)(2)(3)三个小区。<br>
(1) AAA1-AFFE，码位 564 个。<br>
(2) F8A1-FEFE，码位 658 个。<br>
(3) A140-A7A0，码位 672 个。<br>
第(3)区尽管对用户开放，但限制使用，因为不排除未来在此区域增补新字符的可能性。<br>
GBK具体字符的编码值及编码规则可查看[此工具网站](https://www.qqxiuzi.cn/zh/hanzi-gbk-bianma.php)。

<br>

5. <b>GB18030</b><br>
   GB18030编码采用单字节、双字节、四字节分段编码方案，具体码位见下文。GB18030向下兼容GBK和GB2312编码。<br>
   国家标准GB18030-2005《信息技术 中文编码字符集》是我国继GB2312-1980和GB13000-1993之后最重要的汉字编码标准，是我国计算机系统必须遵循的基础性标准之一。 GB18030有两个版本：GB18030-2000和GB18030-2005。GB18030-2000是GBK的取代版本，它的主要特点是在GBK基础上增加了CJK统一汉字扩充A的汉字。GB18030-2005的主要特点是在GB18030-2000基础上增加了CJK统一汉字扩充B的汉字。<br>
   GB18030-2000编码标准《信息技术 汉字编码字符集 基本集的扩充》是由信息产业部和国家质量技术监督局在<b>2000年3月17日</b>联合发布的，并且将作为一项国家标准在<b>2001年的1月</b>正式强制执行。GB18030-2000仅规定了常用非汉字符号和27533个汉字（包括部首、部件等）的编码。<br>
   GB18030-2005《信息技术 中文编码字符集》是以汉字为主并包含多种我国少数民族文字的超大型中文编码字符集，其中收入汉字70000余个。在GB18030-2000的基础上增加了42711个汉字和多种我国少数民族文字的编码（如藏、蒙古、傣、彝、朝鲜、维吾尔文等）。增加的这些内容是推荐性的，原GB18030-2000中的内容是强制性的，市场上销售的产品必须符合。故GB18030-2005为部分强制性标准，自发布之日起代替GB18030-2000。<br>
> GB18030的特点:<br>
采用变长多字节编码，每个字可以由1个、2个或4个字节组成。<br>
编码空间庞大，最多可定义161万个字符。<br>
完全支持Unicode，无需动用造字区即可支持中国国内少数民族文字、中日韩和繁体汉字以及emoji等字符。<br>
GB18030在其标准中以码表形式定义了除去代理对外的全部Unicode码位的定义，因此算得上是一种Unicode的变换格式（UTF）。由于GB18030基本上是绕开已分配的码点去指定需要对应的Unicode，其变换和UTF-8相比要复杂得多。在日常实现上，常常会直接使用一个偏移量表<br>
GB 18030在微软视窗系统中的代码页为54936。<br>
GB18030具体字符的编码值及编码规则可查看[此工具网站](https://www.qqxiuzi.cn/zh/hanzi-gb18030-bianma.php)。

<br>

> <b>常见字符集的应用场景</b><br>
> UTF-8：主要用于网络传输，数据库存储。<br>
> UTF-16：一般用于程序内部逻辑处理，比如关于字符串的处理算法，相对于UTF-8的字节流，会更容易定位到某个要处理的字符。<br>
> GBK：纯中文数据环境下，使用GBK进行存储，数据传输相对于UTF-8会更好。这也是windows系统的默认locale。<br>

<br>
<br>


### 二、编译过程中的字符编码转换
1. 相关的重要概念：<br>
> <b>源码字符集：</b><br>
> "the source character set"，指的是源代码文件是使用何种字符集保存的。<br>
> <b>执行字符集：</b><br>
> "the execution character set"，是指源代码经过编译、链接后的可执行文件是使用何种编码字符集保存的，程序实际执行时，内存中的字符串编码就是执行字符集。<br>
> <b>运行环境编码：</b><br>
> 是指操作系统（或者当前控制台环境）用于显示文字的编码字符集。<br>

<br>

2. <b>乱码的根源：</b><br>
> 源代码文件(<b>源码字符集</b>)经过编译/链接，生成可执行文件(<b>执行字符集</b>)，最后程序运行于实际环境中(<b>运行环境编码</b>)。在这过程中如果有字符集不匹配，最终就无法显示预期的文字信息，甚至产生乱码。
> 1. 编译器在编译源代码时，会将<b>源码字符集转化为执行字符集</b>，如果编译器不能正确识别源码字符集，就得不到正确的字符串数据。
> 2. 可执行文件在实际运行环境中执行时，为了在控制台（或者其他UI）上显示出字符串，就要将<b>执行字符集转化为运行环境的字符集</b>。如果运行环境的字符集与执行字符集不同，也会导致乱码。

> <b>总结起来，要想使程序不会乱码，必须满足：</b>
> 1. 编译器准确识别了源码字符集，从而得到正确的字符串数据（执行字符集）。
> 2. 运行环境的编码与执行字符集相同。<br>

<br>

3. <b>源文件字符集与编译</b><br>
不同的编译器对上述转换过程的支持不一样，如MSVC不同于GCC
> <b>MSVC 10(VS2010)：</b><br>
> 1. 识别“源码字符集：<br>
> 源码文件有BOM签名的，就按BOM的编码来解析源文件；<br>
> 否则使用本地Locale字符集解析源文件（随系统设置而变）。<br>
> 2. 转化“执行字符集”：<br>
   对于<b>char类型(ANSI字符串)</b>，如果设置了<b>预处理选项“#pragma execution_character_set”</b>，编译源码时，转换为预编译所设定的执行字符集；<br>
   如果源码字符集是UTF-8编码的，则执行字符集也是UTF-8的。<br>
   其他情况则使用本地Locale作为执行字符集。<br>
   对于<b>wchar_t类型(宽字符串)</b>，总是使用UTF-16编码。<br>

<br>

> <b>GCC：</b><br>
> GCC的源码字符集与执行字符集默认都是UTF-8编码，也就是说默认情况下GCC都是按UTF-8来解析源码，编译后的执行字符集也是UTF-8。<br>
> 当然GCC也提供改变默认情况的编译选项（注意是编译过程中的选项，不是链接过程）。

    -finput-charset=charset    用于指定源码字符集
    -fexec-charset=charset     用于指定执行字符集

<br>

 上述转换对应关系大致如下表：Locale是GBK(Code Page: 936)

> MSVC:

|源代码|	内存中的字符串	|可执行文件中的字串常量|写入文件|
|:----:|:----:|:----:|:----:|
|GBK	|GBK|	GBK	|GBK|
|UTF-16 BE (BOM)|	GBK|	GBK|GBK|
|UTF-16 LE (BOM) |GBK|	GBK	|GBK|
|UTF-8 (BOM)|GBK|	GBK|GBK|
|UTF-8|	UTF-8	|UTF-8|	UTF-8|

> GCC:

|源代码|	内存中的字符串	|可执行文件中的字串常量|写入文件|
|:----:|:----:|:----:|:----:|
|GBK	|GBK|	GBK	|GBK|
|UTF-16 BE (BOM)|	编译出错：不识别 BOM (FF FE)|	GBK|GBK|
|UTF-16 LE (BOM) |编译出错：不识别 BOM (FE FF)|	GBK	|GBK|
|UTF-8 (BOM)|编译出错：不识别BOM (EF BB BF)|	GBK|GBK|
|UTF-8|	UTF-8	|UTF-8|	UTF-8|

### 三、编程中经常遇见的编码问题
1. <b>ANSI字符和Unicode字符与字符串的数据类型，以及默认的编码方式：</b><br>
   char c = 'A';<br>
   char szBuffer[100] = "A String";<br><br>
   typedef unsigned short wchar_t; <br>
   wchar_t c = L'A'; &ensp;&ensp;<br>
   wchar_t szBuffer[100] = L"A string"; <br><br>

   char&nbsp;:&nbsp;默认ANSI编码(ASCII，单字节)， 不可以存储其他ansi扩展字符<br>
   wchar&nbsp;:&nbsp;默认Unicode编码(UTF-16)，定义时需要使用L标明，否则会因为locale出现预期之外的结果。<br>
   如MSVC中会使用GBK编码,因为windows的locale默认是GBK。

<br>

1. <b>Unicode与ANSI函数：</b><br>
> windows中的Unicode与ANSI函数：<br>
    (1) 关于字符串的函数一般都存在两种形式，一种处理ANSI字符串，另一种处理Unicode字符串。比如：<br>
    #ifdef UNICODE <br>
    #define CreateWindowEx  CreateWindowExW <br>
    #else <br>
    #define CreateWindowEx  CreateWindowExA <br>
    #endif <br><br>
   (2) 在windows vista中， CreateWindowExA就只是作为一个转换层，它就负责分配内存，将ANSI字符串转换为Unicode字符串。<br>
   然后再调用CreateWindowExW，向其传递转换后的Unicode字符串进行处理。<br><br>
   (3) 现在，Microsoft逐渐开始倾向于某些函数只提供Unicode版本。如：ReadDirectoryChangesW和CreateProcessWithLogonW。<br>
   <b>由上面几点可以看出来，我们现在更应该使用Unicode函数，而非ANSI函数。所以在VS项目工程中，应当配置选项“使用Unicode字符集”。从而让编译器增加宏定义——UNICODE。</b>
<br>

> C运行库中的Unicode与ANSI函数：<br>
   与windows函数一样，C运行库也提供了一系列函数来处理ANSI字符和字符串，并提供另一系列函数来处理Unicode字符和字符串。<br>
   但是，与windows函数最大的区别就是，C运行库中的两个系列函数都是独立的。即ANSI系列函数的内部不会做字符串的转换和调用Unicode的函数。Unicode系列函数也是如此。<br>
   比如：在C运行库中，strlen返回一个ANSI字符串的长度，而wcslen返回Unicode字符串的长度。

<br>

3. <b>Unicode与ANSI字符串的转换函数：MultiByteToWideChar与WideCharToMultiByte (win32API)</b><br>

>  (1) 使用<b>MultiByteToWideChar</b>可以将多字节字符串转换为宽字节字符串，原型如下：<br><br>
   <b>int MultiByteToWideChar(</b><br>
      <b>UINT &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[CodePage](https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar),</b>&ensp;&ensp; &nbsp;&nbsp;&nbsp;// 标识了与多字节字符串相关联的代码页值(code page)<br>
      <b>DWORD &ensp;&ensp;[dwFlags](https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar),</b>&ensp;&ensp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;// 更多额外的控制，常为0<br>
      <b>PCSTR &ensp;&ensp;&nbsp;&nbsp;&nbsp;pMultiByteStr,</b>&nbsp;&nbsp;// 要转换的多字节字符串(ANSI字符串)<br>
      <b>int &ensp;&ensp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cbMultiByte,</b>&ensp;&ensp;// 指定字符串的长度(字节数)，如果为-1，函数便可自动判断源字符串的长度。<br>
      <b>PWSTR &ensp;&ensp;&nbsp;&nbsp;pWideCharStr,</b> &nbsp;// 转换结果的缓冲区<br>
      <b>int&ensp;&ensp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cchWideChar</b>  &nbsp;&nbsp;// 缓冲区的最大长度(字符数)<必须指定><br>
      <b>);</b><br><br>
   注：如果调用MultiByteToWideChar，并给cchWideChar参数传入0，函数就不会执行转换,而是返回一个宽字符数(包括了'\0')，
   只有当缓冲区能够容纳该数量的宽字符时，转换才会成功。<br><br>
   用法步骤具体如下：<br>
   (1) 调用MultiByteToWideChar，为pWideCharStr参数传入NULL，为cchWideChar参数传入0，为cbMultiByte参数传入-1。<br>
   (2) 分配一块足以容纳转换后的Unicode字符串的内存。它的大小上一个MultiByteToWideChar调用的返回值乘以sizeof(wchar_t)。<br>
   (3) 再一次调用MultiByteToWideChar，这一次将缓冲区地址作为pWideCharStr参数的值传入。将第一次MultiByteToWideChar调用的返回值乘以sizeof(wchar_t)后得到的大小作为cchWideChar参数的值传入。<br>
   (4) 使用转换后的字符串。<br>
   (5) 释放Unicode字符串占用的内存块。<br>
   示例如下：更多细节可参考[Microsoft Docs](https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar)。
   
    DWORD dBufSize = MultiByteToWideChar(CP_ACP, 0, pMultiByteStr, -1, NULL, 0);
    wchar_t* dBuf = new wchar_t[dBufSize];
    int nRet = MultiByteToWideChar(CP_ACP, 0, pMultiByteStr, -1, dBuf, dBufSize * sizeof(wchar_t));

    { /* 使用转换后的字符串 */ }

    delete[] dBuf;
   
> (2) 使用<b>WideCharToMultiByte</b>可以将宽字节字符串转换为多字节字符串。其使用步骤与MultiByteToWideChar大致相似。<br>
   更多细节可参考[Microsoft Docs](https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-widechartomultibyte)。

<br>

1. <b>ATL字符串转换类:</b>
> ATL3中提供了<b>字符串转换宏</b>，如T2A、A2T等<br>
不过使用它们需要借助本地变量,因此在使用之前需要声明USES_CONVERSION宏来声明本地变量.<br>
而且还有个很大的缺陷:<br>
转换宏总是使用栈存储,它们在运行时调用_alloca在本地栈上分配额外的空间,<br>
如果在函数中循环地进行转换,很可能因为栈空间用尽而崩溃,因为栈空间在函数退出后才能释放。<br>
还有个很严重的问题:若在C++ catch块中使用转换宏,_alloca调用会搅乱栈上的异常跟踪信息而使程序崩溃。<br><br>
<b>此外T2A在分配缓冲区内存的时候，它所分配的内存可能不足以存储转换后的ANSI字符串，如UTF-16转为UTF-8</b>。<br>
由于上述缺陷，在ATL7中引入了<b>字符串转换类</b>,所有的类采用统一的命名格式:C<源格式简写>2<目标格式简写>。<br>
如CT2A用于将UNICODE字符串转换为ANSI字符串。 使得字符串转换更为安全好用。<br>

    // ATL3字符串转换宏
    #define W2A(lpw) (\
	((_lpw = lpw) == NULL) ? NULL : (\
		(_convert = (static_cast<int>(wcslen(_lpw))+1), \
		(_convert>INT_MAX/2) ? NULL : \
		ATLW2AHELPER((LPSTR) alloca(_convert*sizeof(WCHAR)), _lpw, _convert*sizeof(WCHAR), _acp))))
    #define T2A W2A

    // ATL7字符串转换类
    template< int t_nBufferLength = 128 >
    class CW2AEX { ... };
    typedef CW2AEX<> CW2A;
    #define CT2A CW2A
    
<br>

5. <b>如何判断字符串当前编码，如何判断是否存在中文:</b>
> <b>IsTextUnicode</b></br>
  该函数可以<b>有助于</b>分辨文本的编码格式。它使用一系列统计性和确定性方法来猜测缓冲区的内容。所以可能返回错误的结果。<br>
  它的函数原型是：<br>
  BOOL &nbsp; IsTextUnicode(const &nbsp;VOID &nbsp;*pvBuffer, &nbsp;int &nbsp; size, &nbsp;LPINT &nbsp;[lpiResult](https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-istextunicode));<br>
  (1) pvBuffer参数指向要测试的缓冲区的地址。<br>
  (2) size参数指定pvBuffer缓冲区的字节数。测试的字节数越多越准确<br>
  (3) [lpiResult](https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-istextunicode)是一个整数的地址，在调用IsTextUnicode之前必须初始化这个整数，从而指出希望执行哪些测试。如果传入NULL，则将执行所有测试。<br>
   返回值：如果认为测试缓冲区包含的是Unicode文本，就返回TRUE。否则返回FALSE。<br>

<br>

> <b>字符串中是否存在中文</b><br>
> 如果只有英文字母和汉字组成的字符串，那么直接判断单字节是否大于0x80即可。<br>
> 如果含有多国语言，则需要查看相应编码格式的中文编码范围。

<br>
<br>
<br>

    下表是ASCII码表：
|DEC|	OCT	|HEX|	BIN	|缩写(符号)	|描述| DEC|	OCT	|HEX|	BIN	|缩写(符号)	|描述|
|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|0	|000	|00	|00000000	|NUL	|Null char (空字符)|64	|100	|40	|01000000	|@		|At symbol|
|1	|001	|01	|00000001	|SOH	|Start of Heading (标题开始)|65	|101	|41	|01000001	|A		|Uppercase A|
|2	|002	|02	|00000010	|STX	|Start of Text (正文开始)|66	|102	|42	|01000010	|B		|Uppercase B|
|3	|003	|03	|00000011	|ETX	|End of Text (正文结束)|67	|103	|43	|01000011	|C		|Uppercase C|
|4	|004	|04	|00000100	|EOT	|End of Transmission (传输结束)|68	|104	|44	|01000100	|D		|Uppercase D|
|5	|005	|05	|00000101	|ENQ	|Enquiry (请求)|69	|105	|45	|01000101	|E		|Uppercase E|
|6	|006	|06	|00000110	|ACK	|Acknowledgment (收到通知)|70	|106	|46	|01000110	|F		|Uppercase F|
|7	|007	|07	|00000111	|BEL	|Bell (响铃)|71	|107	|47	|01000111	|G		|Uppercase G|
|8	|010	|08	|00001000	|BS	|Back Space (退格)|72	|110	|48	|01001000	|H		|Uppercase H|
|9	|011	|09	|00001001	|HT	|Horizontal Tab (水平制表符)|73	|111	|49	|01001001	|I		|Uppercase I|
|10	|012	|0A	|00001010	|LF	|Line Feed (换行键)|74	|112	|4A	|01001010	|J		|Uppercase J|
|11	|013	|0B	|00001011	|VT	|Vertical Tab (垂直制表符)|75	|113	|4B	|01001011	|K		|Uppercase K|
|12	|014	|0C	|00001100	|FF	|Form Feed (换页键)|76	|114	|4C	|01001100	|L		|Uppercase L|
|13	|015	|0D	|00001101	|CR	|Carriage Return (回车键)|77	|115	|4D	|01001101	|M		|Uppercase M|
|14	|016	|0E	|00001110	|SO	|Shift Out / X-On (不用切换)|78	|116	|4E	|01001110	|N		|Uppercase N|
|15	|017	|0F	|00001111	|SI	|Shift In / X-Off (启用切换)|79	|117	|4F	|01001111	|O		|Uppercase O|
|16	|020	|10	|00010000	|DLE		|Data Line Escape (数据链路转义)|80	|120	|50	|01010000	|P		|Uppercase P|
|17	|021	|11	|00010001	|DC1		|Device Control 1 (设备控制1)|81	|121	|51	|01010001	|Q		|Uppercase Q|
|18	|022	|12	|00010010	|DC2		|Device Control 2 (设备控制2)|82	|122	|52	|01010010	|R		|Uppercase R|
|19	|023	|13	|00010011	|DC3		|Device Control 3 (设备控制3)|83	|123	|53	|01010011	|S		|Uppercase S|
|20	|024	|14	|00010100	|DC4		|Device Control 4 (设备控制4)|84	|124	|54	|01010100	|T		|Uppercase T|
|21	|025	|15	|00010101	|NAK		|Negative Acknowledgement (拒绝接收)|85	|125	|55	|01010101	|U		|Uppercase U|
|22	|026	|16	|00010110	|SYN		|Synchronous Idle (同步空闲)|86	|126	|56	|01010110	|V		|Uppercase V|
|23	|027	|17	|00010111	|ETB		|End of Transmit Block (传输块结束)|87	|127	|57	|01010111	|W		|Uppercase W|
|24	|030	|18	|00011000	|CAN		|Cancel (取消)|88	|130	|58	|01011000	|X		|Uppercase X|
|25	|031	|19	|00011001	|EM	 	  |End of Medium (介质中断)|89	|131	|59	|01011001	|Y		|Uppercase Y|
|26	|032	|1A	|00011010	|SUB		|Substitute (替补)|90	|132	|5A	|01011010	|Z		|Uppercase Z|
|27	|033	|1B	|00011011	|ESC		|Escape (溢出)|91	|133	|5B	|01011011	|[		|Opening bracket|
|28	|034	|1C	|00011100	|FS		|File Separator (文件分割符)|92	|134	|5C	|01011100	|\		|Backslash|
|29	|035	|1D	|00011101	|GS		|Group Separator (分组符)|93	|135	|5D	|01011101	|]		|Closing bracket|
|30	|036	|1E	|00011110	|RS		|Record Separator (记录分离符)|94	|136	|5E	|01011110	|^		|Caret - circumflex|
|31	|037	|1F	|00011111	|US	 	|Unit Separator (单元分隔符)|95	|137	|5F	|01011111	|_		|Underscore|
|32	|040	|20	|00100000	| 		|Space (空格)|96	|140	|60	|01100000	|`		|Grave accent|
|33	|041	|21	|00100001	|!		|Exclamation mark|97	|141	|61	|01100001	|a		|Lowercase a|
|34	|042	|22	|00100010	|"		|Double quotes|98	|142	|62	|01100010	|b		|Lowercase b|
|35	|043	|23	|00100011	|#		|Number|99	|143	|63	|01100011	|c		|Lowercase c|
|36	|044	|24	|00100100	|$		|Dollar|100	|144	|64	|01100100	|d		|Lowercase d|
|37	|045	|25	|00100101	|%		|Procenttecken|101	|145	|65	|01100101	|e		|Lowercase e|
|38	|046	|26	|00100110	|&		|Ampersand|102	|146	|66	|01100110	|f		|Lowercase f|
|39	|047	|27	|00100111	|'		|Single quote|103	|147	|67	|01100111	|g		|Lowercase g|
|40	|050	|28	|00101000	|(		|Open parenthesis|104	|150	|68	|01101000	|h		|Lowercase h|
|41	|051	|29	|00101001	|)		|Close parenthesis|105	|151	|69	|01101001	|i		|Lowercase i|
|42	|052	|2A	|00101010	|*		|Asterisk|106	|152	|6A	|01101010	|j		|Lowercase j|
|43	|053	|2B	|00101011	|+		|Plus|107	|153	|6B	|01101011	|k		|Lowercase k|
|44	|054	|2C	|00101100	|,		|Comma|108	|154	|6C	|01101100	|l		|Lowercase l|
|45	|055	|2D	|00101101	|-		|Hyphen|109	|155	|6D	|01101101	|m		|Lowercase m|
|46	|056	|2E	|00101110	|.		|Period, dot or full stop|110	|156	|6E	|01101110	|n		|Lowercase n|
|47	|057	|2F	|00101111	|/		|Slash or divide|111	|157	|6F	|01101111	|o		|Lowercase o|
|48	|060	|30	|00110000	|0		|Zero|112	|160	|70	|01110000	|p		|Lowercase p|
|49	|061	|31	|00110001	|1		|One|113	|161	|71	|01110001	|q		|Lowercase q|
|50	|062	|32	|00110010	|2		|Two|114	|162	|72	|01110010	|r		|Lowercase r|
|51	|063	|33	|00110011	|3		|Three|115	|163	|73	|01110011	|s		|Lowercase s|
|52	|064	|34	|00110100	|4		|Four|116	|164	|74	|01110100	|t		|Lowercase t|
|53	|065	|35	|00110101	|5		|Five|117	|165	|75	|01110101	|u		|Lowercase u|
|54	|066	|36	|00110110	|6		|Six|118	|166	|76	|01110110	|v		|Lowercase v|
|55	|067	|37	|00110111	|7		|Seven|119	|167	|77	|01110111	|w		|Lowercase w|
|56	|070	|38	|00111000	|8		|Eight|120	|170	|78	|01111000	|x		|Lowercase x|
|57	|071	|39	|00111001	|9		|Nine|121	|171	|79	|01111001	|y		|Lowercase y|
|58	|072	|3A	|00111010	|:		|Colon|122	|172	|7A	|01111010	|z		|Lowercase z|
|59	|073	|3B	|00111011	|;		|Semicolon|123	|173	|7B	|01111011	|{		|Opening brace|
|60	|074	|3C	|00111100	|<		|Less than|124	|174	|7C	|01111100	||		|Vertical bar|
|61	|075	|3D	|00111101	|=		|Equals|125	|175	|7D	|01111101	|}		|Closing brace|
|62	|076	|3E	|00111110	|>		|Greater than|126	|176	|7E	|01111110	|~		|Equivalency sign (tilde)|
|63	|077	|3F	|00111111	|?		|Question mark|127	|177	|7F	|01111111	|	  	|Delete|

    
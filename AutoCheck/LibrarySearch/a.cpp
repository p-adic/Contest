// c:/Users/user/Documents/Programming/Contest/AutoCheck/LibrarySearch/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../SampleAnalyser/a_Body.hpp"

AC( LibrarySearch )
{
  ASK_NUMBER(
	     "明示式の計算問題" ,
	     "最大／最小化問題" ,
	     "数え上げ問題" ,
	     "求解問題" ,
	     "クエリ処理問題" ,
             "シミュレーション問題" ,
	     "ゲーム問題" ,
	     "真偽判定問題" ,
	     "構築問題" ,
	     "質問による推定"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpression );
  } else if( num == num_temp++ ){
    CALL_AC( Maximisation );
  } else if( num == num_temp++ ){
    CALL_AC( Counting );
  } else if( num == num_temp++ ){
    CALL_AC( Solving );
  } else if( num == num_temp++ ){
    CALL_AC( Query );
  } else if( num == num_temp++ ){
    CALL_AC( Simulation );
  } else if( num == num_temp++ ){
    CALL_AC( Game );
  } else if( num == num_temp++ ){
    CALL_AC( Decision );
  } else if( num == num_temp++ ){
    CALL_AC( Construction );
  } else if( num == num_temp++ ){
    CALL_AC( Deduction );
  }
  CERR( "" );
  CERR( "ライブラリー探索は以上です。終了します。" );
}

AC( ExplicitExpression )
{
  ASK_NUMBER(
             "総和や総乗の計算問題" ,
	     "固定長引数関数や格子点上の関数や配列の計算問題" ,
	     "順列上の関数の計算問題" ,
	     "グラフ上の関数の計算問題" ,
	     "序数の計算問題" ,
	     "確率／期待値の計算問題" ,
	     "操作回数の計算問題" ,
	     "時系列変化後の状態計算問題" ,
	     "始／終切片和や畳み込みの計算問題" ,
	     "面積の計算問題" ,
	     "極限の計算問題" ,
             "その他の数論的関数の計算問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionSum );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArray );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionFunctionOnPermutation );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionFunctionOnGraph );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionOrder );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionProbability );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionCountingOperation );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionTimeSeriesChange );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionConvolution );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArea );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionLimit );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArithmetic );
  }
}

AC( ExplicitExpressionSum )
{
  ASK_YES_NO( "列の長さや操作の回数の総和ですか？" );
  if( reply == "y" ){
    CERR( "長さや回数を1の和として表し、多重総和に帰着させましょう。" );
  }
  ASK_YES_NO( "総和や総乗を取る項数は指数オーダーですか？" );
  if( reply == "y" ){
    CERR( "- 総和や総乗を個数で平均化することで期待値計算に帰着" );
    CERR( "- 総和を0,1の和で表して確率計算に帰着" );
    CERR( "を検討しましょう。" );
    CALL_AC( ExplicitExpressionProbability );
  } else {
    ASK_NUMBER(
               "一重和や一重積の計算問題" ,
               "二重和や二重積や積和の計算問題"
               );
    if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionArraySum );
    } else if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionDoubleSum );
    }
  }
}

AC( ExplicitExpressionArraySum )
{
  ASK_YES_NO( "１重和や１重積を複数回求める問題ですか？" );
  if( reply == "y" ){
    CERR( "２重和や２重積を求める問題と同様に処理しましょう。" );
    CALL_AC( ExplicitExpressionDoubleSum );
  } else {
    ASK_NUMBER(
               "商の総和の計算問題" ,
               "剰余の総和の計算問題" ,
               "１つの配列の成分を受け取る関数の総和の計算問題" ,
               "２つの配列の内積の計算問題" ,
               "１つの配列の部分列を受け取る関数の総和の計算問題" ,
               "配列を受け取る関数の配列をわたる総和の計算問題" ,
               );
    if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionQuotientSum );
    } else if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionResidueSum );
    } else if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionOneArrayEntrySum );
    } else if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionInnerProduct );
    } else if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionOneArraySubArraySum );
    } else if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionArrayCombinatorial );
    }
  }
}

AC( ExplicitExpressionQuotientSum )
{
  CERR( "- f(x)+g(x)*floor(ax+b/c)などの総和はfloor_sumと同様の再帰" );
  CERR( "  \\Mathematics\\Combinatorial\\FloorSum" );
  CERR( "- floor(c/(ax+b))などの総和は同じ値で纏め上げる平方分割" );
  CERR( "  \\Mathematics\\Combinatorial\\FloorSum\\FloorRiemanZeta" );
  CERR( "- a*floor(x/c)-b*floor(x/d)などが閾値を超える最小値は" );
  CERR( "  floor(x/c)の差分が正の時にのみ達成できるのでx=cy（yは整数）" );
  CERR( "  の形に帰着" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionResidueSum )
{
  CERR( "- sum_x c%xはc-floor(c/x)*xと表してfloor(c/x)が同じ値で纏め上げる" );
  CERR( "  平方分割" );
  CERR( "  \\Mathematics\\Combinatorial\\ResidueSum" );
  CERR( "- sum_x x%cは(sum_x x)%cなので2cを法として等差数列の和の公式に帰着" );
  CERR( "  \\Mathematics\\Arithmetic\\Iteration" );
}

AC( ExplicitExpressionOneArrayEntrySum )
{
  CERR( "1変数関数f(x)と配列(a_i)_{i=0}^{N-1}に対するsum_i f(a_i)などを考える" );
  CERR( "とします。必要ならば(a_i)_iをソートして広義単調増加とします。" );
  CERR( "- f(a_{i+1}) - f(a_i)がO(1)で計算できO(N)が間に合いそうならば、" );
  CERR( "  f(a_i)の差分計算による高速化" );
  CERR( "- f(a_i)がiに関する等比数列K個の和で表せO(K log N)が間に合いそうならば" );
  CERR( "  等比数列の総和の公式" );
  CERR( "  \\Mathematics\\Arithmetic\\Power\\GeometricProgression" );
  CERR( "- f(a_i)がK次正方行列AとK次元ベクトルvを用いて(A^i v)[0]と表せ" );
  CERR( "  - A-Eが正則でO(K^3 log N)が間に合いそうならば、等比数列の総和の公式" );
  CERR( "    \\Mathematics\\LinearAlgebra" );
  CERR( "    \\Mathematics\\Arithmetic\\Power\\GeometricProgression" );
  CERR( "  - A-Eが正則とは限らずO(K^3 log N)が間に合いそうならば、vにf(a_i)の" );
  CERR( "    累積和を末尾挿入し、行列累乗" );
  CERR( "    \\Mathematics\\LinearAlgebra" );
  CERR( "- f(a_i)がiに関してK個の条件分岐を持つ漸化式で表せO(K)が間に合いそうならば" );
  CERR( "  条件分岐で総和を分割して総和の漸化式を求める分割統治法による再帰" );
  CERR( "- #im(f)が小さくf(a_)の各点逆像が計算しやすいならば" );
  CERR( "  fの各点逆像による纏め上げをする分割統治法" );
  CERR( "  sum_i f(a_i)=sum_y #f(a_)^{-1}(y) y" );
  CERR( "- #im(f)が小さくfが非負でf(a_)の始切片逆像が計算しやすいならば" );
  CERR( "  fの始切片逆像による纏め上げをする分割統治法" );
  CERR( "  sum_i f(a_i)=sum_{y>=1} #f(a_)^{-1}([y,∞))" );
  CERR( "- #dom(f)が小さく(a_)の逆像が計算しやすいならば" );
  CERR( "  (a_)の各点逆像による纏め上げをする分割統治法" );
  CERR( "  sum_i f(a_i)=sum_x #(a_)^{-1}(x) f(x)" );
  CERR( "- Nが大きい場合と小さい場合で解法の折衷" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionInnerProduct )
{
  CERR( "数列(a_i)_iと(b_i)_iが与えられるとします。" );
  CERR( "f(X) = sum_{i=0}^{N-1} a_i X^i" );
  CERR( "g(X) = sum_{i=0}^{N-1} b_{N-i-1} X^i" );
  CERR( "と置きます。" );
  ASK_NUMBER(
             "(sum_{i=0}^{N-i-j} a_i b_{i+j})_{j=0}^{N-1}の計算"
             "(sum_{i=0}^{N-1} a_i b_{i+j})_{j=0}^{N-1}の計算"
             );
  if( num == num_temp++ ){
    CERR( "f(X)g(X)mod X^N = sum_{i=0}^{N-1} c_i X^i" );
    CERR( "と置くと" );
    CERR( "(c_{N-1-j})_{j=0}^{N-1}" );
    CERR( "が答えです。" );
  } else if( num == num_temp++ ){
    CERR( "f(X)g(X) = sum_{i=0}^{2N-2} c_i X^i" );
    CERR( "と置くと" );
    CERR( "(sum_{k \equiv -1-j mod N}c_k)_{j=0}^{N-1}" );
    CERR( "が答えです。" );
  }
  CERR( "\\Mathematics\\Polynoial\\Truncate" );
}

AC( ExplicitExpressionOneArraySubArraySum )
{
  ASK_NUMBER(
             "連続部分列への分割に関する関数の総和の計算問題" ,
             "連続とは限らない部分列への分割に関する関数の総和の計算問題"
             );
  if( num == num_temp++ ){
    CERR( "配列の添字集合は全順序集合なので、木の分割の問題に一般化されます。" );
    CALL_AC( ExplicitExpressionFunctionOnTree );
    CERR( "" );
    CERR( "更にfが部分列の長さに関する再帰的な構造を持つ場合、全ての連続部分列に" );
    CERR( "対しfの値を前計算することを検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "配列の並び換えによって答えが変わらないので、適切にソートしてから" );
    CERR( "計算することを検討しましょう。" );
  }
}

AC( ExplicitExpressionArrayCombinatorial )
{
  CERR( "長さNの配列の有限集合Sと、Sを定義域に持つ関数fが与えられているとして、" );
  CERR( "sum_{A in S} f(A)を求めます。" );
  CERR( "- 任意のA in Sに対し" );
  CERR( "  f(A) = sum_{i=0}^{N-1} g(A,i)" );
  CERR( "  を満たす関数gが存在するならば、" );
  CERR( "  sum_{A in S} f(A) = sum_{A in S} sum_{i=0}^{N-1} g(A,i)" );
  CERR( "                    = sum_{i=0}^{N-1} sum_{A in S} g(A,i)" );
  CERR( "  によりg(-,i)の逆像の数え上げ問題に帰着" );
  CERR( "- 任意のA in Sに対し" );
  CERR( "  f(A) = #{i in [0,N)|P(A,i)} " );
  CERR( "  を満たす関係Pが存在するならば、Pの特性関数をgと置けば任意のA in Sに対し" );
  CERR( "  f(A) = sum_{i=0}^{N-1} g(A,i)" );
  CERR( "  が成り立つので上の場合に帰着" );
  CERR( "- 任意のA in Sに対し" );
  CERR( "  f(A) = prod_{i=0}^{N-1} g(A,i)" );
  CERR( "  を満たす関数gが存在するならば、積の和典型などの組み合わせ論的解釈" );
  CERR( "  https://ei1333.hateblo.jp/entry/2021/07/30/144201" );
  CERR( "  https://ladywingclover.hatenablog.com/entry/2022/11/24/084524" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionDoubleSum )
{
  ASK_NUMBER(
             "商の総和の計算問題" ,
             "剰余の総和の計算問題" ,
             "その他の総和の計算問題"
             );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionDoubleSumQuotient );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionDoubleSumResidue );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionDoubleSumNonQuotient );
  }
}

AC( ExplicitExpressionDoubleSumQuotient )
{
  CERR( "floor内部の分数の分子か分母を固定して一重総和計算に帰着させましょう。" );
  ASK_NUMBER(
             "分母か分子が一次式で与えられる問題" ,
             "分母と分子が配列で与えられる問題"
             );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionQuotientSum );
  } else {
    CERR( "sum_i sum_j floor(a_i/b_j)の形の計算問題は、b_jの重複を頻度表で管理して" );
    CERR( "b_jが無重複かつ単調である場合に帰着させ、" );
    CERR( "- iを固定してjを動かすならば答えをA[i]に格納するとして、" );
    CERR( "  iを走査してB_iをfloor(a_i/整数)の形で固定してb_j<=B_iの範囲では" );
    CERR( "  A[i]に愚直に一点加算、b_j>B_iの範囲では各1<=v<floor(a_i/B)に対し" );
    CERR( "  floor(a_i/b_j)=vを満たすjの区間長*vをA[i]に一点加算" );
    CERR( "- jを固定してiを動かすならば答えをA[j]に格納するとして、" );
    CERR( "  iを走査してB_iをfloor(a_i/整数)の形で固定してb_j<=B_iの範囲では" );
    CERR( "  A[j]たちに愚直に一点加算、b_j>B_iの範囲では各1<=v<floor(a_i/B)に対し" );
    CERR( "  floor(a_i/b_j)=vを満たすjの区間でAにvを区間加算" );
    CERR( "\\Mathematics\\Combinatorial\\FloorSum\\Parallel" );
    CERR( "を検討しましょう。" );
  }
}

AC( ExplicitExpressionDoubleSumResidue )
{
  CERR( "sum_x sum_y h(g_1(x)%g_2(y))はg_1(x)かg_2(y)の値を固定して" );
  CERR( "一重総和計算に帰着させましょう。" );
  ASK_NUMBER(
             "分母か分子が一次式で与えられる問題" ,
             "分母と分子が配列で与えられる問題"
             );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionResidueSum );
  } else {
    CERR( "sum_{i=0}^{N-1} sum_{j=0}^{M-1} a_i%b_jは" );
    CERR( "- O(min(N+M+(max_i a_i)log M,(M log M)+sum_i(sqrt(a_I log M))))" );
    CERR( "  が間に合いそうならばiを固定するごとの計算" );
    CERR( "  - floor(a_i/b_j)の値でjを纏め上げ" );
    CERR( "  - b_jの頻度表を用いてエラトステネスの要領で" );
    CERR( "    b_jの倍数を前計算しa_iに関する差分計算" );
    CERR( "- O((M log M)+sum_i(sqrt(a_i log M))))" );
    CERR( "  が間に合いそうならば分母を固定して商に帰着" );
    CERR( "を検討しましょう。" );
    CERR( "\\Mathematics\\Combinatorial\\ResidueSum\\Parallel" );
  }
}

AC( ExplicitExpressionDoubleSumNonQuotient )
{
  CERR( "2変数関数f(x,y)と配列(a_i)_{i=0}^{N-1}, (b_j)_{j=0}^{M-1}に対する" );
  CERR( "二重和X_i Y_j f(a_i,b_j)などを考えるとします。X,Yは" );
  CERR( "sum,prod,min,maxなどです。" );
  CERR( "必要ならば(a_i)_iと(b_j)をソートしてともに広義単調増加とします。" );
  ASK_NUMBER(
             "X=Y=sum" ,
             "X=Y=prod" ,
             "X=Y=min,max" ,
             "X!=YかつY=sum" ,
             "X!=YかつY=prod" ,
             "X!=YかつY=min,max"
             );
  CERR( "- iやjなどに関する動的計画法" );
  if( num < 3 ){
    CERR( "- X_i f(a_i,b_j)の計算量をO(g(N))としてO(g(N)M)が間に合いそう" );
    CERR( "  ならば、順序交換X_i Y_j f(a_i,b_j) = Y_j X_i f(a_i,b_j)" );
  }
  CERR( "- Y_j f(a_i,b_j)のiに関する差分計算" );
  if( num == 0 || num == 3 ){
    CERR( "  - Y_j(f(a_i,b_{j+1})-f(a_i,b_j))の式変形による計算" );
  } else if( num == 1 || num == 4 ){
    CERR( "  - Y_j(f(a_i,b_{j+1})/f(a_i,b_j))の式変形による計算" );
  } else if( num == 2 || num == 5 ){
    CERR( "  - 順序多重集合{f(a_i,b_j)}_jをiに関して差分計算" );
    CERR( "- Y = maxでmax_j f(a_i,b_j)が[0,R]値ならば、各r in [1,R]ごとに" );
    CERR( "  r <= max_j f(a_i,b_j)を満たすiの個数g(r)を求めて" );
    CERR( "  sum_{r=1}^{R} g(r)を計算" );
  }
  CERR( "を検討しましょう。" );
  if( num == 0 ){
    ASK_YES_NO( "f(x,y)=sum_k g_k(x) h_k(y)と表示できますか？" );
    if( reply == "y" ){
      CERR( "O(K(N+M))が間に合いそうならば、積和の和積化" );
      CERR( "  X_i Y_j f(a_i,b_j) = sum_k((X_i g_k(a_i))(Y_j h_k(b_j)))" );
      CERR( "を検討しましょう。" );
    }
  }
  if( num == 2 ){
    ASK_YES_NO( "N=MかつX=Y=max（minの場合は-1倍）でf(a_i,b_j)の代わりにmin(f(a_i,b_j),f(a_j,b_i))などを考えますか？" );
    if( reply == "y" ){
      CERR( "f(a_i,b_j)<f(a_j,b_i)の必要十分条件を求めてそれを満たすj全体" );
      CERR( "の集合S_iを考え、max_i max_{j in S_i} f(a_i,b_j)に帰着" );
      CERR( "- fが積や比ならf(a_i,b_j)<f(a_j,b_i)は比や積のソートに帰着" );
      CERR( "- S_iはiに関する差分計算" );
      CERR( "を検討しましょう。" );
    }
  }
  if( num < 3 ){
    ASK_YES_NO( "#im(f)が小さいですか？" );
    if( reply == "y" ){
      CERR( "- f(a_,b_)の各点逆像{(i,j)|f(a_i,b_j)=z}が計算しやすいならば" );
      CERR( "  各点逆像による纏め上げをする分割統治法" );
      CERR( "  X_i Y_j f(a_i,b_j)=X_z #f(a_,b_)^{-1}(z) cdot z" );
      if( num == 0 ){
        CERR( "- fが非負でf(a_,b_)の終切片逆像{(i,j)|f(a_i,b_j)>=z}が" );
        CERR( "  計算しやすいならば終切片逆像による纏め上げをする分割統治法" );
        CERR( "  X_i Y_j f(a_i,b_j)=X_{z>0} #f(a_,b_)^{-1}([z,∞))" );
      }
      CERR( "を検討しましょう。" );
    }
    ASK_YES_NO( "#dom(f)が小さいですか？" );
    if( reply == "y" ){
      CERR( "(a_,b_)の各点逆像{(i,j)|(a_i,b_j)=v}が計算しやすいならば" );
      CERR( "(a_,b_)の各点逆像による纏め上げをする分割統治法" );
      CERR( "  X_i Y_j f(a_i,b_j)=X_v #(a_,b_)^{-1}(v) f(v)" );
      CERR( "を検討しましょう。" );
    }
  }
}

AC( ExplicitExpressionArray )
{
  ASK_NUMBER(
	     "線形漸化式の計算問題" ,
	     "非線形漸化式の計算問題" ,
	     "１変数関数の反復合成の計算問題" ,
	     "bit関数と他の関数の合成の計算問題" ,
	     "その他の１変数関数／配列の計算問題" ,
             "その他の多変数関数／配列を受け取る関数の計算問題" ,
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryLinearRecursion );
  } else if( num == num_temp++ ){
    CERR( "漸化式に現れる各additive principalな項を成分に持つベクトル列を考え、" );
    CERR( "それが満たす線形漸化式を考えましょう。" );
    CERR( "" );
    CALL_AC( ExplicitExpressionUnaryLinearRecursion );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryIteration );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionBitwiseFunction );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryOther );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionMultivariable );
  }
}

AC( ExplicitExpressionUnaryLinearRecursion )
{
  CERR( "L項間線形漸化式" );
  CERR( "a_n = sum(i,0,L){c_i a_{n-L+i}} (n>=L)" );
  CERR( "第N項a_Nを法Bで求めます。" );
  CERR( "" );
  CERR( "適宜Z/B Zの型" );
  CERR( "\\Mathematics\\Arithmetic\\Mod\\ConstexprModulo" );
  CERR( "\\Mathematics\\Arithmetic\\Mod\\QuotientRing" );
  CERR( "を用いて" );
  CERR( "- O(LN)が間に合いそうならば直近L+1項をメモ化する動的計画法" );
  CERR( "- O(L^3 log N)が間に合いそうならば行列累乗" );
  CERR( "  \\Mathematics\\LinearAlgebra" );
  CERR( "- O(L + log max{L,N} log N)が間に合いそうならば" );
  CERR( "  sum_{i,0,L-1} a_i x^i/(1-sum(i,0,L){c_i x^i})" );
  CERR( "  のN次係数のボスタン森法による計算" );
  CERR( "  \\Mathematics\\Polynomial\\BostanMori" );
  CERR( "- 係数列(c_i)_iが周期Pを持ちO(PN log N)が間に合いそうならばP個の区間加算BIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalAddo" );
  CERR( "- 係数列(c_i)_iが単調でD階差分が定数列でO((N+L)D)が間に合いそうならば" );
  CERR( "  「係数列のd階Δ^d(c_i)_i差分と(a_i)_{i=n-L+d+1}^{n}の内積dp[n][d]」" );
  CERR( "  を管理する動的計画法" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionUnaryIteration )
{
  CERR( "定義域の要素数N、テストケース数T、反復回数の上限Kとします。" );
  CERR( "- O((N + T)log_2 K)が通りそうならばダブリング" );
  CERR( "  \\Mathematics\\Function\\Iteration\\Doubling" );
  CERR( "- O(TN)が通りそうならばループ検出" );
  CERR( "  \\Mathematics\\Function\\Iteration\\LoopDetection" );
  CERR( "- O(N)すら通らなさそうならば関数の規則性を見付けるための実験" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionBitwiseFunction )
{
  CERR( "(M,*)を可換モノイドとします。写像f:N^n->(M,*)がbit準同型とは" );
  CERR( "- (a&b)==0を満たす任意のa,bに対しf(a|b)=f(a)*f(b)" );
  CERR( "を満たすということとします。" );
  CERR( "" );
  CERR( "例えば" );
  CERR( "- 恒等写像:N->(N,+)" );
  CERR( "- 恒等写像:N->(N,|)" );
  CERR( "- 恒等写像:N->(N,^)" );
  CERR( "- 固定の元との2項bit演算:N->(N,+)" );
  CERR( "- 二進法表記:N->(N^{oplus N},+)" );
  CERR( "- 二進法の桁和:N->(N,+)" );
  CERR( "- 二進法表記と加法的準同型の合成:N->(Z,+)" );
  CERR( "- 二進法表記と乗法的準同型の合成:N->(Z,*)" );
  CERR( "- ２つのbit関数f,g:N->(M,*)の各点積fg:N->(M,*)" );
  CERR( "- ２つのbit関数f,g:N->(M,*)の直積の積f*g:N^2->(M,*)" );
  CERR( "- (M,*)が群である場合のbit関数f:N->(M,*)と逆元の合成" );
  CERR( "などがbit準同型です。" );
  ASK_NUMBER(
	     "(Z,+)へのbit準同型" ,
	     "(Z,*)へのbit準同型の線形和"
	     );
  if( num == num_temp++ ){
    CERR( "ノード数nの根付き木上の関数tと引数2のbit演算otimesに対し、" );
    CERR( "多引数化otimes:N^n->Nとbit準同型f:N->(Z,+)の合成に" );
    CERR( "tを代入した値をf(t)と略記します。" );
    CERR( "" );
    CALL_AC( FunctionOnTree );
    CERR( "" );
    CALL_AC( ExplicitExpressionBitFunctionOnTree );
  } else if( num == num_temp++ ){
    CERR( "N^nの部分集合Sとbit準同型f:N^n->(Z,*)に対し、" );
    CERR( "Sの要素aをわたるf(a)の総和は、aの各成分をbitに分解して" );
    CERR( "f(a)を積で表示し、その途中までの積の総和を管理する" );
    CERR( "桁DPを検討しましょう。" );
  }
}

AC( ExplicitExpressionUnaryOther )
{
  CERR( "まずは小さい入力の場合を愚直に計算し、OEISで検索しましょう。" );
  CERR( "https://oeis.org/?language=japanese" );
  CERR( "" );
  CERR( "次に出力の定義と等価な式を考察しましょう。" );
  CERR( "- 単調ならば、冪乗や階乗" );
  CERR( "- 定義にp進法が使われていれば、各種探索アルゴリズム" );
  CERR( "- 入力が素数に近い場合に規則性があれば、p進付値、p進法、" );
  CERR( "  オイラー関数、約数の個数など" );
  CERR( "- 鳩の巣原理による周期性" );
  CERR( "  - mod Bフィボナッチ数列やその累積和の周期は短い。" );
  CERR( "  - mod(プロス素数-1)では偶数倍の周期が短い。" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "そして前計算を試みましょう。候補としては" );
  CERR( "- 階乗／逆元／場合の数" );
  CERR( "- 素数列挙" );
  CERR( "- １つまたは複数の整数の約数列挙" );
  CERR( "- オイラー関数の値の列挙" );
  CERR( "- サブゴールとなる関係式を満たす解の列挙" );
  CERR( "があります。特に漸化式による前計算が可能な場合、法または周期を" );
  CERR( "バケット分割してソースコードに埋め込む高速化を検討しましょう。" );
  ASK_YES_NO( "整数値単調関数の各値の計算問題ですか？" );
  if( reply == "y" ){
    CERR( "fを単調関数とし各i in [0,N)に対するf(i)を求める問題を考えます。" );
    ASK_YES_NO( "fは非負単調減少であり、かつfは減少の早い優関数gを持ちますか？" );
    if( reply == "y" ){
      CERR( "fの各点での愚直な計算量の上界をKと置きます。" );
      CERR( "閾値B in [0,N)を固定し、各i in [0,B)に対してf(i)を愚直に求める" );
      CERR( "計算量はO(BK)です。各i in [B,N)に対してf(i) in [0,g(B)]であり" );
      CERR( "各k in [0,g(B)]に対しf(i)<=kを満たす最大値を二分探索で求める" );
      CERR( "計算量はO(g(B)K log_2 g(B))です。" );
      CERR( "合わせて計算量がO(BK+g(B)K log_2 g(B))で抑えられたので、" );
      CERR( "g(B)の形に従って相加相乗平均などで最適化しましょう。" );
      ASK_YES_NO( "g(i) = N/(i+1)などと取れますか？" );
      if( reply == "y" ){
        CALL_AC( ExplicitExpressionMonotone );
        CERR( "https://codeforces.com/blog/entry/134445" );
      }
    } else {
      ASK_YES_NO( "f(i)を含む区間Iが与えられた時、f(i)をIの濃度の線形オーダーなどで求められますか？" );
      if( reply == "y" ){
        CALL_AC( ExplicitExpressionMonotone );
      }
    }
  }
}

AC( ExplicitExpressionMonotone )
{
  CERR( "monotone minimaの要領で、fの定義域を再帰的に二等分していき、" );
  CERR( "終域を分割していきましょう。" );
}

AC( ExplicitExpressionMultivariable )
{
  CERR( "- 各引数に関して線形であるならば、標準基底に制限して計算" );
  CERR( "- 累積和などの操作を繰り返すならば、" );
  CERR( "  - 母関数の1/(1-x)倍などに翻訳" );
  CERR( "    \\Mathematics\\Polynomial\\Cumulative" );
  CERR( "  - 格子点上の経路数え上げに翻訳" );
  CERR( "    https://en.wikipedia.org/wiki/Pascal%27s_triangle#Overall_patterns_and_properties" );
  CERR( "    https://en.wikipedia.org/wiki/Catalan%27s_triangle" );
  CERR( "- 交代和などの操作を繰り返すならば、２回纏めて累積和に帰着" );
  CERR( "- 差分などの操作を繰り返すならば、母関数の1-x倍などに翻訳" );
  CERR( "- 積分作用素を繰り返すならば、変数変換してint dxなどに帰着" );
  CERR( "- 微分作用素を繰り返すならば、変数変換してd/dxなどに帰着" );
  CERR( "- AがB>1で割り切れる回数の計算は" );
  CERR( "  - min_{p|B} floor(v_p(A)/v_p(B))" );
  CERR( "    = floor(min_{p|B} v_p(A)/v_p(B))" );
  CERR( "  - min_{p|B} (p^v_p(A)がp^v_p(B)で割り切れる回数)" );
  CERR( "- A,B>1に対するmin_{p|B} (v_p(A)/v_p(B))の計算は" );
  CERR( "  max_{X=1}^{floor(log_2(B))} min_{p|B} floor(v_p(A^X)/v_p(B))/X" );
  CERR( "  = max_{X=1}^{floor(log_2(B))} (A^XがBで割り切れる回数)/X" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionFunctionOnPermutation )
{
  ASK_NUMBER(
	     "１つの順列に関する値の計算問題" ,
	     "順列を受け取る関数の総和の計算問題"
	     );
  if( num == num_temp++ ){
    CERR( "- 符号そのものの計算問題は" );
    CERR( "  - O(N log_2 N)やO(N^2)が間に合いそうなら転倒数の計算" );
    CERR( "  - O(N log_2 N)が間に合わなさそうなら互換表示（O(N)）" );
    CERR( "- 符号と何かの積の和は行列式に帰着させ、" );
    CERR( "  - 行列式そのものなら行基本変形（O(N^3)）" );
    CERR( "  - 余因子展開の途中の値が必要ならメモ化再帰（O(N 2^N)）" );
    CERR( "を検討しましょう。" );
    CERR( "" );
    CERR( "転倒数は" );
    CERR( "- O(N^2)が通りそうならば愚直な二重ループ" );
    CERR( "- O(N log_2 N)が通りそうならば可換群BIT" );
    CERR( "  \\Mathematics\\Combinatorial\\Permutation" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
    CERR( "で計算しましょう。" );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArrayCombinatorial );
    CERR( "" );
    CERR( "条件を満たす順列全体をわたる転倒数の総和／期待値は、" );
    CERR( "各i<jごとにそこで転倒が生じる順列の個数を計算し、その総和／期待値を" );
    CERR( "取りましょう。条件が良ければ、転倒が生じる順列の個数は転倒が生じるとは" );
    CERR( "限らない順列の個数の半分となります。" );
  }
}

AC( ExplicitExpressionFunctionOnGraph )
{
  CERR( "次数d以上の頂点数のdを渡る総和は2Eです。従ってd以上の頂点を走査する" );
  CERR( "処理を各dに対し行ってもO(E)回の処理となります。" );
  ASK_YES_NO( "グラフは木に限りますか？" );
  if( reply == "y" ){
    CALL_AC( ExplicitExpressionFunctionOnTree );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionFunctionOnNonTreeGraph );
  }
}

AC( ExplicitExpressionFunctionOnTree )
{
  ASK_NUMBER(
	     "最短経路長総和の計算問題" ,
	     "木を受け取る関数の計算問題" ,
	     "木上の関数の総和の計算問題" ,
             "木の非空部分集合の連結包の計算問題" ,
	     "構文木の計算問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( TreeWeightSum );
  } else if( num == num_temp++ ){
    CERR( "木を受け取る関数fが与えられているとします。" );
    CERR( "" );
    CALL_AC( FunctionOnTree );
    CERR( "- 各ノード（またはその近傍）の寄与に分解できる時はノードごとの計算" );
    CERR( "- 部分木に関する良い遷移関係があれば（全方位）木DP" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Tree" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Tree\\RootingDP" );
    CERR( "  - 動的配列や集合や連想配列などを扱う際はデータ構造をマージする一般的なテク" );
    CERR( "を検討しましょう。" );
    ASK_YES_NO( "fが何かしらのbitごとの和などで与えられる問題ですか？" );
    if( reply == "y" ){
      CALL_AC( ExplicitExpressionBitFunctionOnTree );
    }
  } else if( num == num_temp++ ){
    CALL_AC( QueryTree );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionConnectedHullInTree );
  } else if( num == num_temp++ ){
    CERR( "構文解析は言語の再帰式に沿って再帰関数で実装しましょう。" );
    CERR( "例えば式Sを左から順に読み、" );
    CERR( "Expression(S,読んでいる位置i,式番号v,構文木T)を" );
    CERR( "「S[i]を演算子または始端とする式eに番号vを振り、" );
    CERR( " Tにeの部分式の式番号へ有向辺を張り、iとvを増やす」" );
    CERR( "という処理を式の再帰式に従っていくつかの関数に分けて" );
    CERR( "再帰すると良いです。" );
    CERR( "https://qiita.com/kazuki_tamaribuchi/items/77a4b4e6214646a079ed" );
    CERR( "" );
    CERR( "構文木に沿った計算は、演算を１つ以外の引数を固定した１変数関数とみなし" );
    CERR( "合成として処理し、分割統治とcompress+rakeを組み合わせてO(N(log N)^3)で" );
    CERR( "処理することを検討しましょう。" );
    CERR( "https://en.wikipedia.org/wiki/Tree_contraction#Expression_Evaluation" );
    CERR( "https://yukicoder.me/submissions/940108" );
  }
}

AC( TreeWeightSum )
{
  CERR( "木の最短経路長は、最短経路長総和の可換群を用いて木DPを検討しましょう。" );
  CERR( "\\Mathematics\\Algebra\\Monoid\\Group\\TreeWeight" );
}

AC( ExplicitExpressionBitFunctionOnTree )
{
  CERR( "Tの各頂点vごとに、vを根とする部分木の情報を用いてbit演算などで計算される値" );
  CERR( "A[v]があるとします。" );
  CERR( "dp[v][j][s]=「vを根とする部分木内でAの値のj桁目のbit状態sの個数」" );
  CERR( "などを管理するv,j,sに関する木DPを検討しましょう。" );
  CERR( "" );
  CERR( "これはTが{0,1,...,N-1}に通常の順序の逆順序を入れたものである場合は" );
  CERR( "「第i成分で切った部分列でのj桁目のbitがs（=0,1）である個数dp[i][j][s]」" );
  CERR( "を管理することに他なりません。" );
}

AC( FunctionOnTree )
{
  CERR( "木の２頂点間距離は1の和とみなすことで辺ごとの寄与に分解できます。" );
  CERR( "" );
  CERR( "木Tの分割Pに対し、Pの各成分pを渡るf(p)の総和をF(P)と置きます。" );
  CERR( "Tに根を固定し、深さ優先探索でTの頂点にラベルづけをします。" );
  CERR( "" );
  CERR( "Pの各成分pに対しpの各頂点のラベルの最小値をD(p)と置き、" );
  CERR( "Dについて昇順にPを並べます。" );
  CERR( "" );
  CERR( "Pの末尾成分pを削除した分割P'が元の木からpを削除した木の分割であり" );
  CERR( "F(P)=F(P')+f(p)と表せることに注意しましょう。" );
}

AC( ExplicitExpressionFunctionOnNonTreeGraph )
{
  ASK_NUMBER(
	     "ホモロジー群の計算問題" ,
	     "最短経路長総和の計算問題" ,
	     "ハッシュの計算問題" ,
             "その他の計算問題"
	     );
  if( num == num_temp++ ){
    CERR( "- 体係数ならば、掃き出し法により階数を計算しましょう。" );
    CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\Modint" );
    CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\Bitset" );
    CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\Real" );
    CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\Complex" );
    CERR( "- 体でないPID係数ならば、スミス標準形を計算しましょう。" );
    CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\Int\\ElementaryDivisor" );
  } else if( num == num_temp++ ){
    CERR( "なもり先生グラフならば、非サイクル部の各連結成分の木の最短経路長総和" );
    CERR( "を求め、内積を畳み込みで高速化しましょう。" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Tree\\WeightSum\\Namori" );
    CALL_AC( TreeWeightSum );
  } else if( num == num_temp++ ){
    CERR( "各頂点の適当な不変量（次数など）をグラフ畳み込みしましょう。" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Convolution" );
  } else if( num == num_temp++ ) {
    CERR( "- 部分集合上の関数の計算問題は" );
    CERR( "  - O(N 2^N)が間に合いそうなら高速ゼータ変換／メビウス変換" );
    CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "  - O(N^2)が間に合いそうで要素数にのみ依存するならマーラー変換" );
    CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform\\MahlerTransform" );
    CERR( "- その他の順序集合上の関数の計算問題はゼータ変換／メビウス変換" );
    CERR( "  \\Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "- 辺に重みが付けられたグラフ上の２点を結ぶ経路（もしくは頂点の重複のない経路）P" );
    CERR( "  全体をわたってPに沿った辺の重みの総乗f(P)を考えf(P)の下限を計算する問題は" );
    CERR( "  - 重みが「単位元が最小元である等号つき全順序モノイドM個の直積」に値を持ち" );
    CERR( "    O(M(V+E)log V)が間に合いそうならば各直積成分に対するダイクストラ法" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
    CERR( "  - 重みが「単位元が最小元であるmeet半束モノイド」に値を持ち" );
    CERR( "    O(V^3)が間に合いそうならばワーシャルフロイド法" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\FloydWarshall" );
    CERR( "を検討しましょう。" );
  }
}

AC( ExplicitExpressionConnectedHullInTree )
{
  CERR( "非空部分集合Sの連結包はオイラーツアーでSの各点をcyclicに並べた時の" );
  CERR( "隣接2項のパスの和集合です。" );
  CERR( "それ自体が木なので、頂点数は辺長+1すなわちパス長総和/2+1です。" );
  CERR( "\\Mathematics\\Geometry\\Graph\\DepthFirstSearch\\Tree\\EulerTour" );
}

AC( ExplicitExpressionOrder )
{
  ASK_NUMBER(
	     "与えられた順序集合に関する問題" ,
	     "順序集合を更新する問題" ,
             "与えられた01列の辞書順最小の部分列の計算問題"
	     );
  if( num == num_temp++ ){
    CERR( "多重集合Sを何らかの順序でソートした配列aに関する問題を考えます。" );
    ASK_NUMBER(
	       "与えられた要素sに対しs=a[i]を満たすiを求める問題" ,
	       "与えられたiに対するa[i]を求める問題" ,
	       "与えられたiに対するa[0],...,a[i]を全て求める問題"
	       );
    if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionOrderOfElement );
    } else if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionRandomAccess );
    } else if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionTotalAccess );
    }
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayOrder );
  } else if( num == num_temp++ ){
    CERR( "0をL個、1をR個選ぶ際の辞書順最小の部分列は、" );
    CERR( "0を左からL個、1を右からR個貪欲に選ぶことで求まります、" );
  }
}

AC( ExplicitExpressionOrderOfElement )
{
  ASK_YES_NO( "各iごとにa[i]が高速に求められる問題ですか？" );
  if( reply == "y" ){
    CERR( "iに関する二分探索を検討しましょう。" );
  } else {
    CERR( "s未満のSの項の数え上げを検討しましょう。" );
    CALL_AC( CountingArrayBoundedTotal );
    ASK_YES_NO( "Sが固定長変数関数の逆像で与えられますか？" );
    if( reply == "y" ){
      CERR( "固定長変数関数の逆像の数え上げ問題は、" );
      CALL_AC( CountingExplicitExpression );
    }
  }
}

AC( ExplicitExpressionRandomAccess )
{
  ASK_YES_NO( "Sが後続を高速に計算可能な部分集合の排他的和集合で表せますか？" );
  if( reply == "y" ){
    CERR( "Sがソート済みの多重集合M個の和集合でO((M+i)log M)が間に合いそうならば、" );
    CERR( "各多重集合の先頭項を集めたpriority_queueからi回pop＋後続挿入" );
    CERR( "を検討しましょう。" );
    CERR( "" );
  }
  CERR( "Sの各要素sごとにs未満のSの項数を高速に解けるか否かで場合分けをします。" );
  CERR( "そのためにSの性質についていくつか確認をします。" );
  ASK_YES_NO( "Sが固定長変数関数の像で与えられますか？" );
  if( reply == "y" ){
    CERR( "固定長変数関数の逆像の数え上げ問題は、" );
    CALL_AC( CountingExplicitExpression );
  }
  ASK_YES_NO( "Sの各要素sごとにs未満のSの要素数が高速に求まりますか？" );
  if( reply == "y" ){
    CERR( "Sの各要素sごとにs未満のSの項を数え上げ問題を考えて、" );
    CERR( "sに関する二分探索を検討しましょう。" );
    CALL_AC( CountingArrayBoundedTotal );
  } else {
    ASK_YES_NO( "SからQへの自然な単射順序保存写像であってSの要素間の幅が1以上となるものがありますか？" );
    if( reply == "y" ){
      CERR( "各格子点の間（半開区間）にSの要素は高々1個しかなく、a[i]以下の最大の" );
      CERR( "格子点はSと始切片(-∞,m)の共通部分の要素数がi以上となる最小のmなので、それを" );
      CERR( "二分探索などで求めましょう。後はm<=a[i]<m+1の条件からa[i]を決定しましょう。" );
      CERR( "" );
    }
    CERR( "以下、Sを文字列の集合とします。数は位取り記法で文字列とみなします。" );
    CERR( "- 文字列の長さLが固定でありi<<(Sの要素数)であるならば、a[i]の先頭" );
    CERR( "  が辞書順最小の文字に確定するのでLが小さいケースに帰着。" );
    CERR( "  - 文字の種類数をσとし、σ^Lが高々10^6のオーダーであるならば、" );
    CERR( "    Sの要素とは限らない文字列をσ進表記で整数に対応させて全探策。" );
    CERR( "- 文字cを辞書順昇順に走査し、先頭1文字目をcに決め打った時のSの要素数を" );
    CERR( "  iから引けるだけ引き、引けなくなったらcをa[i]の先頭1文字目に確定させ" );
    CERR( "  a[i]の長さが1少ない場合に帰着させられ、再帰的にa[i]を計算。" );
  }
}

AC( ExplicitExpressionTotalAccess )
{
  CERR( "- 各iごとにa[i]が高速に求められるならば、a[i]以下のSの要素の全列挙" );
  CERR( "- Sがソート済みの多重集合M個の和集合でO((M+i)log M)が間に合いそうならば、" );
  CERR( "  各多重集合の先頭項を集めたpriority_queueからi回pop＋後続挿入" );
}

AC( ExplicitExpressionProbability )
{
  // "部分集合の要素数の期待値か否か"
  CEXPR( int , subset_size , 0 );
  // "グリッドの黒マスの個数の期待値か否か"
  CEXPR( int , black_tile_size , subset_size + 1 );
  // "転倒数の期待値か否か"
  CEXPR( int , inversion_num , black_tile_size + 1 );
  // "単位時間に高々1回独立に起こる事象の起きた回数の期待値か否か"
  CEXPR( int , indep_event_count , inversion_num + 1 );
  // "裏が出るまでのコイン投げ回数の期待値か否か"
  CEXPR( int , coin_count , indep_event_count + 1 );
  // "nを確率的に減らしてi以下にする試行回数の期待値か否か"
  CEXPR( int , reduce_count , coin_count + 1 );
  // "コンプガチャを達成するまでの回数の期待値か否か" ,
  CEXPR( int , complete_collection_cost , reduce_count + 1 );
  // "操作／遷移回数の期待値か否か"
  CEXPR( int , operation_count , complete_collection_cost + 1 );
  // "N個の確率変数X_1,...,X_Nのj番目の値の期待値か否か"
  CEXPR( int , j_th_value , operation_count + 1 );
  // "N個の確率変数X_1,...,X_Nの総和の二乗の期待値か否か"
  CEXPR( int , sum_square , j_th_value + 1 );
  vector<bool> type( sum_square + 1 );
  ASK_YES_NO( "期待値の計算問題ですか？" );
  if( reply == "y" ){
    ASK_NUMBER(
               "個数の期待値" ,
               "回数の期待値" ,
               "値の期待値"
               );
    if( num == num_temp++ ){
      ASK_YES_NO( "部分集合の要素数の期待値ですか？" );
      type[subset_size] = reply == "y";
      ASK_YES_NO( "グリッドの黒マスの個数の期待値ですか？" );
      type[black_tile_size] = reply == "y";
      ASK_YES_NO( "転倒数の期待値ですか？" );
      type[inversion_num] = reply == "y";
    } else if( num == num_temp++ ){
      ASK_NUMBER(
              "単位時間に高々1回独立に起こる事象の起きた回数の期待値" ,
              "裏が出るまでのコイン投げ回数の期待値" ,
              "nを確率的に減らしてi以下にする試行回数の期待値" ,
              "コンプガチャを達成するまでの回数の期待値" ,
              "その他の操作／遷移回数の期待値" ,
              "その他の回数の期待値"
              );
      if( num == num_temp++ ){
        type[indep_event_count] = true;
        type[operation_count] = true;
      } else if( num == num_temp++ ){
        type[coin_count] = true;
        type[operation_count] = true;
      } else if( num == num_temp++ ){
        type[reduce_count] = true;
        type[operation_count] = true;
      } else if( num == num_temp++ ){
        type[complete_collection_cost] = true;
        type[operation_count] = true;
      } else if( num == num_temp++ ){
        type[operation_count] = true;
      } else {
        // 候補なし
      }
    } else if( num == num_temp++ ){
      ASK_YES_NO( "転倒数の期待値ですか？" );
      type[inversion_num] = reply == "y";
      ASK_YES_NO( "N個の確率変数X_1,...,X_Nのj番目の値の期待値ですか？" );
      type[j_th_value] = reply == "y";
      ASK_YES_NO( "N個の確率変数X_1,...,X_Nの総和の二乗の期待値ですか？" );
      type[sum_square] = reply == "y";
    }
    CERR( "- 期待値計算は" );
    CERR( "  - 確率を用いた愚直な計算" );
    CERR( "  - 対象を和で表して線形性" );
    if( type[subset_size] || type[black_tile_size] || type[inversion_num] ){
      CERR( "    - 部分集合の要素数の期待値は各要素が部分集合に属す確率の和に帰着" );
    }
    if( type[black_tile_size] ){
      CERR( "      - グリッドのランダムな矩形塗り潰しの黒マスの個数は矩形に属す確率を" );
      CERR( "        矩形ごとに包除原理で足し引き" );
      CERR( "        - 矩形のサイズが固定ならば、ベルヌーイ数前計算による冪乗関数の" );
      CERR( "          総和を用いた明示式" );
      CERR( "          \\Mathematics\\Polynomial\\Cumulative\\GridStampCoveringExpectation" );
      if( type[inversion_num] ){
        CERR( "      - ランダムな順列Pの転倒数はP[i]>P[j]を満たす確率p(i,j)の総和" );
      }
    }
    if( type[operation_count] ){
      CERR( "  - 操作／遷移回数は期待値間の関係式を求め行列累乗やボスタン森法" );
      CERR( "    \\Mathematics\\LinearAlgebra" );
      CERR( "    \\Mathematics\\Polynomial\\BostanMori" );
    }
    if( type[indep_event_count] ){
      CERR( "    - 単位時間に高々1回独立に起こる事象の起きた回数の期待値は" );
      CERR( "      各時刻tごとに+1の起こる確率p(t)の総和" );
    }
    if( type[coin_count] ){
      CERR( "    - 裏が出るまでのコイン投げ回数の期待値は、n回以上表が出る確率p(n)の総和" );
    }
    if( type[reduce_count] ){
      CERR( "    - nを確率的に減らしてi以下にする試行回数の期待値E(n,i)は、" );
      CERR( "      - 各i<j<=nに対してnから1回でjに行く確率をP(n,j)として" );
      CERR( "        E(n,i)=sum_{i<j<=n} P(n,j)(1+(i<j?E(j,i):0)" );
      CERR( "        すなわち" );
      CERR( "        E(n,i)=(P(n,n)+sum_{i<j<n} P(n,j)(1+(i<j?E(j,i):0))/(1-P(n,n))" );
      CERR( "      - 各i<j<=nに対してnから一度でもjに行く確率をQ(n,j)として" );
      CERR( "        E(n,i)=sum_{j>i} Q(n,j)E(j,j-1)" );
      CERR( "        であり、" );
      CERR( "        - Q(n,j)=sum_{j<m<=n} P(n,m)*Q(m,j)" );
      CERR( "          すなわち" );
      CERR( "          Q(n,j)=(sum_{j<m<n} P(n,m)*Q(m,j))/(1-P(n,n))" );
      CERR( "        - Q(n,j)=sum_{j<m<=n} Q(n,m)*sum_k (1-P(m,m))^kP(m,j)" );
      CERR( "          =(sum_{j<m<=n} Q(n,m)*P(m,j)/P(m,m)" );
      CERR( "      - 写像f_n:[1,M_n]->[0,n]と一様ランダムなm in [1,M_n]を用いて" );
      CERR( "        n->f_n(m)と遷移する場合、" );
      CERR( "        E(n,i)=1+(sum_{m=1}^{M_n} E(f_n(m),i))/M_n" );
      CERR( "        すなわち" );
      CERR( "        E(n,i)=(1+(sum_{m=1}^{n-1} #(f_n^{-1}(m)) E(m,i))/M_n)" );
      CERR( "               /(1-#(f_n^{-1}(n))/M_n)" );
      CERR( "              =(M_n+sum_{m=1}^{n-1} #(f_n^{-1}(m)) E(m,i))" );
      CERR( "               /(M_n-#(f_n^{-1}(n)))" );
      CERR( "        と著せ、f_n次第でmをある程度纏めあげたE(f_n(m),i)や" );
      CERR( "        #(f_n^{-1}(m)) E(m,i)の総和が累積和などを用いて" );
      CERR( "        nに関して高速な差分計算が可能" );
    }
    if( type[complete_collection_cost] ){
      CERR( "    - コンプ条件の設定されたガチャの試行回数の期待値は、" );
      CERR( "      適切に状態を定義して" );
      CERR( "      dp[s] = 状態sからの試行回数の期待値" );
      CERR( "      を管理するsに関する動的計画法（終了状態から逆順に計算）" );
      CERR( "      Mathematics\\Analysis\\Probability\\ExpectedTrialCount" );
    }
    if( type[j_th_value] ){
      CERR( "  - N個の確率変数X_1,...,X_Nのj番目Y_jなら、Y_j<=yを#{i|X_i<=y}>=jに" );
      CERR( "    読み替えることで、X_iの累積密度関数F_iを用いてY_jの累積密度関数G_j(y)を" );
      CERR( "    prod_i(zF_i(y)+(1-F_i(y))のj次以上の係数和で表し、" );
      CERR( "    E[Y_j] = int_{R} y G_j'(y) dyを計算" );
    }
    if( type[sum_square] ){
      CERR( "  - N個の確率変数X_1,...,X_Nの総和の二乗なら二乗の総和と" );
      CERR( "    cross termに分解して期待値を計算" );
      CERR( "    \\Mathematics\\Analysis\\Probability\\Distribution" );
    }
  }
  CERR( "- 確率計算は" );
  CERR( "  - 事象を全探策してそれぞれの確率を計算" );;
  CERR( "  - 余事象や包除原理（高速ゼータ変換／メビウス変換）" );
  CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "  - 対象を独立変数の積で表して乗法性" );
  CERR( "    - グリッドのマスなどの直積集合の要素が矩形領域に属すか否かの確率は" );
  CERR( "      成分ごとの確率の積に帰着" );
  CERR( "  - 同様に確からしい事象の特定" );
  CERR( "    - 母集団S上の関数Xの値がxとなる確率をp(x)とし、与えられた値x_0に対する" );
  CERR( "      p(x_0)を考える場合、Sを排他的に分割して(T_i)_iと置き、各T_iにおいて" );
  CERR( "      Xの値がK_i種類で等確率となる時、求める確率はK_i種類にx_0が入るような" );
  CERR( "      i全体をわたる#T_i/(K_i #S)の総和" );
  CERR( "  - 確率を保つ全射で簡単な事象に帰着" );
  CERR( "  - ベイズの定理" );
  CERR( "を検討しましょう。" );
  ASK_YES_NO( "可換群上でN回以内のランダムな移動で目的地に到達する確率ですか？" );
  if( reply == "y" ){
    CERR( "N回以内の移動で到達する確率は、N以下の各非負整数iに対し" );
    CERR( "ちょうどi回の移動で最初に到達する確率p(i)の総和です。" );
    CERR( "従って(p(i))_iの母関数f(x)の累積和f(x)/(1-x)の計算に帰着されます。" );
    CERR( "ちょうどi回の移動で元の位置戻る確率をq(i)、目的地にいる確率をr(i)回" );
    CERR( "とすると(q(i))_iと(r(i))_iの母関数g(x)とh(x)はfg=hを満たすので、" );
    CERR( "f(x)/(1-x)=h(x)/((1-x)g(x))の係数をボスタン森法で求めましょう。" );
    CERR( "Mathematics\\Polynomial\\BostanMori" );
  }
  ASK_YES_NO( "極限計算ですか？" );
  if( reply == "y" ){
    CALL_AC( ExplicitExpressionLimit );
  }
}

AC( ExplicitExpressionCountingOperation )
{
  CALL_AC( ReducingOperation );
  CALL_AC( CountingOperation );
  CERR( "" );
  CERR( "シミュレーションも検討しましょう。" );
  CALL_AC( SimulateOperation );
}

AC( ReducingOperation )
{
  CERR( "ソートしても操作回数が変わらないならばソートしましょう。" );
  CERR( "" );
  CERR( "操作対象を何らかの不変量で分類し、操作が不変量にもwell-definedである" );
  CERR( "ならば、不変量に注目して方法でなるべく簡単な問題に帰着させましょう。" );
  CERR( "- 頻度表／像／逆像" );
  CERR( "- 総和／最大値／最小値（もしくはその累積値）" );
  CERR( "- 階差数列／最大値と最小値の差" );
  CERR( "- 隣接成分の大小関係" );
  CERR( "- 添字mod Bごとに取り出した部分列の不変量" );
  CERR( "特に、操作回数を不変量の明示式や不変量を用いた貪欲法で計算できないか" );
  CERR( "検討してみましょう。" );
}

AC( CountingOperation )
{
  CERR( "その上で選択の余地のない操作回数を求める際は、" );
  CERR( "- 操作列をイベントとみなし時系列に並べ、「一斉に処理できる区間」いくつか" );
  CERR( "  に分割し、それぞれの区間での処理をまとめて計算" );
  CERR( "- 操作対象が操作優先度つきで複数ある場合は、各操作対象の操作回数に関する動的計画法" );
  CERR( "- 操作がいくつかの対象群に同時に行われるならば、各対象群ごとに回数計算" );
  CERR( "- 操作が辺の削除ならば、逆向きに処理して各連結成分ごとに操作回数を記録" );
  CERR( "- 操作が配列の成分の書き換えならば、" );
  CERR( "  - dp[i] = 第i成分までで打ち切った時の操作回数" );
  CERR( "    としてiに関する動的計画法" );
  CERR( "  - dp[l,r) = 第l成分から第r-1成分まで切り出した時の操作回数などのデータ" );
  CERR( "    区間を中間で分割してマージする分割統治（更新クエリはセグメント木で処理）" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionTimeSeriesChange )
{
  ASK_NUMBER(
             "反復操作を行う問題" ,
             "弾性衝突を行う問題" ,
             "一般の時系列更新クエリを行う問題"
             );
  if( num == num_temp++ ){
    CERR( "配列Aに操作をk回反復した時のi番目の成分をA_{k,i}と置きます。" );
    CERR( "- Aに１つの関数fを合成する操作ならば、fのダブリングか周期計算" );
    CERR( "  Mathematics\\Funciton\\Iteration\\Doubling" );
    CERR( "  Mathematics\\Funciton\\Iteration\\LoopDeection" );
    CERR( "- 配列から配列への関数をAに施す操作ならば、kが小さい時の結果から" );
    CERR( "  一般のA_{k,i}を表すiとkの明示式の予測" );
    CERR( "  - A_kとA_{k+1}で変化のある成分が限られるならば、変化する条件の決定" );
    CERR( "  - 条件A_{k,i} <= aが翻訳できればそれを満たすaの最小値計算" );
    CERR( "  - 添字集合に何らかの有向森構造（葉から根に向う）があり根以外は" );
    CERR( "    その有向辺に沿った成分の移動で与えられる場合、LCA計算" );
    CERR( "    Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Tree" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "弾性衝突を通過に翻訳し、全体の分布を求めましょう。位置関係は" );
    CERR( "弾性衝突で変化しないので、全体の分布を順に見ることで各値が分かります。" );
  } else if( num == num_temp++ ){
    CALL_AC( QueryTimeSeriesChange );
  }
}

AC( ExplicitExpressionConvolution )
{
  ASK_NUMBER(
	     "多項式に関する計算" ,
	     "cup/capに関する計算"
	     "gcd/lcmに関する計算"
	     "その他のjoin半束上の計算"
	     );
  if( num == num_temp++ ){
    CERR( "- 次数の大きな多項式と小さな多項式の積は愚直乗算" );
    CERR( "  Mathematics\\Polynomial\\a.hpp" );
    CERR( "- 通常の積は高速フーリエ変換と中国剰余定理" );
    CERR( "  Mathematics\\Polynomial\\Truncate" );
    CERR( "- 冪乗の積は高速フーリエ変換とexpとlog" );
    CERR( "  Mathematics\\Polynomial\\Truncate" );
    CERR( "- f mod gの逆元計算は" );
    CERR( "  - deg(g)が小さいならば拡張ユークリッドの互助法" );
    CERR( "    Mathematics\\Polynomial\\Mod" );
    CERR( "  - deg(f)が小さいならば1から(g mod f)^{-1}の代表元とg%fの積を引いて" );
    CERR( "    得られるfの倍元をfで割った商" );
    CERR( "- f/gの係数計算はボスタン森法" );
    CERR( "  Mathematics\\Polynomial\\BostanMori" );
  } else if( num == num_temp++ ){
    CERR( "- 部分集合の各部分集合を渡る総和は高速ゼータ変換" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "- 関数値が要素数に依存する場合の畳み込みは高速ゼータ変換／高速メビウス変換" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "- 関数値が要素数に依存しない場合の畳み込みはマーラー変換" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform\\MahlerTransform" );
  } else if( num == num_temp++ ){
    CERR( "- Nの各約数を渡る総和は約数列挙で総和計算" );
    CERR( "  Mathematics\\Arithmetic\\Prime\\Divisor" );
    CERR( "- [1,N]上の関数の畳み込みは約数ゼータ変換／約数メビウス変換" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform\\Divisor" );
    CERR( "- Nの約数上の関数の畳み込みはNを素因数分解した上で約数ゼータ変換の" );
    CERR( "  N/無閉包数での値のみを式変形で計算し各点乗算をして" );
    CERR( "  無閉包数の素因数の個数を使ったメビウス関数で高速メビウス変換の計算" );
    CERR( "  Mathematics\\Arithmetic\\Prime\\Divisor" );
  } else if( num == num_temp++ ){
    CERR( "- 要素sの終切片での総和は隣接代数上のゼータ変換" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "- joinに関する畳み込みは隣接代数上のゼータ変換／メビウス変換" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
  }
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "複数回の乗算は分割統治" );
  CERR( "Mathematics\\Arithmetic\\a.hpp" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionArea )
{
  CERR( "- 三角形の面積は外積" );
  CERR( "  Mathematics\\Geometry\\AffineSpace\\Area" );
  CERR( "- 格子点を頂点に持つ多角形の面積はピックの定理" );
  CERR( "  https://en.wikipedia.org/wiki/Pick%27s_theorem" );
  CERR( "- 凸多角形の面積は１頂点と１辺を用いた三角形分割で三角形に帰着" );
  CERR( "  Mathematics\\Geometry\\AffineSpace\\Area" );
  CERR( "- 関数のグラフで囲まれた領域の面積は積分" );
  CERR( "  - 原始関数による計算" );
  CERR( "  - 区分求積法" );
  CERR( "  - モンテカルロ法" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionLimit )
{
  CERR( "- lim_{T->infty} \\frac{1}{T} sum_{t=1}^{T} a_tの形の計算は" );
  CERR( "  - a_tが収束するならばその値の計算" );
  CERR( "  - a_tが収束しないが周期的ならば周期をPとして" );
  CERR( "    lim_{T->infty} \\frac{1}{P} sum_{t=T+1}^{T+P} a_tの計算" );
  CERR( "    - 周期が短い場合は実際にシミュレーションにより計算" );
  CERR( "    - 鳩の巣原理などで周期的であることは分かってもその具体的な振る舞いが" );
  CERR( "      分からない場合は小さいケースで実験" );
  CERR( "- lim_{N->infty} \\frac{1}{N} sum_{i=1}^{N} f(i/N)の形の計算は" );
  CERR( "  区分求積法" );
  CERR( "  - 法P計算ならば微積分学の基本定理を用いて原始関数の計算に帰着" );
  CERR( "  - 誤差問題ならばモンテカルロ法を用いて近似計算" );
  CERR( "- 整数nごとに定まっている母集団S(n)の要素が条件P(n)を満たす確率p(n)の" );
  CERR( "  n→∞における極限は、別の条件Q(n)を満たす確率q(n)が0に収束するならば、" );
  CERR( "  Q(n)を満たさないもののみを集めた母集団S'(n)の要素が条件P(n)を満たす" );
  CERR( "  確率p'(n)の極限と一致" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionArithmetic )
{
  CERR( "最大公約数と最小公倍数はユークリッドの互除法以外にも" );
  CERR( "素因数分解で計算できることに注意しましょう。" );
}

AC( Maximisation )
{
  ASK_NUMBER(
	     "移動コストの最小化問題" ,
	     "移動コストの最大化問題" ,
	     "ナップサック問題" ,
	     "明示式の最大／最小化問題" ,
	     "配列上の関数に関する最大／最小化問題" ,
	     "配列の隣接成分間関係式を満たす部分列の最長化問題" ,
	     "固定長多変数関数の最大／最小化問題" ,
	     "集合やグラフの部分集合に関する最大／最小化問題" ,
	     "グラフの経路に関する最大／最小化問題" ,
	     "木に関する最大／最小化問題" ,
	     "文字列のマッチングに関する最大／最長化問題" ,
             "分割に関する最大／最小化問題" ,
	     "確率／期待値の最大化問題" ,
	     "必要操作回数／コストの最小化問題" ,
	     "操作継続回数の最大化問題" ,
	     "被覆半径の最小化問題" ,
	     "描画サイズ／個数の最大／最小化問題" ,
	     "条件（方程式など）を満たす数の最大／最小化問題" ,
	     "最小値の最大化／最大値の最小化問題" ,
	     "部分和の最小化問題" ,
	     "部分和の差の最大／最小化問題" ,
	     "2人ゲームの最終的な不変量の最大／最小化問題" ,
             "演算による表示長の最小化問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationMovingDistance );
  } else if( num == num_temp++ ){
    CALL_AC( Knapsack );
  } else if( num == num_temp++ ){
    CERR( "max/minを演算とする総乗の計算問題とみなします。" );
    CALL_AC( ExplicitExpressionSum );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnArray );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationArrayLength );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnAffineSpace );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationSubsetSize );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationGraph );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationOnTree );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationStringMatching );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationPartition );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationProbability );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationOperationCost );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationCountingOperation );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationCoveringSize );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationDrawingImage );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationSolution );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationMinimum );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationSubsetSum );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationSubsetSumDifference );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationGame );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationExpression );
  }
}

AC( MinimisationMovingCost )
{
  CERR( "マルチクエリの場合は、個々のクエリ単位で次の質問に答えてください。例えば" );
  CERR( "１始点多終点コスト最小化を単に複数回繰り返す多始点多終点コスト最小化は" );
  CERR( "１始点多終点コスト最小化を選択してください。" );
  ASK_NUMBER(
	     "１始点多終点コスト最小化（迷路）問題" ,
	     "１始点多中間点１終点コスト最小化（水の採取運搬）問題" ,
	     "１始点多経由点多終点コスト最小化（スタンプラリー）問題" ,
	     "多始点１終点コスト最小化（競争）問題" ,
	     "多始点多終点コスト最大値最小化（開被覆）問題" ,
	     "多始点多終点組み分けコスト最小化（完全二部マッチング）問題" ,
	     "多プレイヤーコスト総和最小化（最小費用流）問題" ,
	     "最近点問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( MinimisationSolvingMaze );
  } else if( num == num_temp++ ){
    CERR( "始点から各中間点への最短経路問題と、終点から各中間点への最短径路問題" );
    CERR( "を両方解くことで１始点多終点コスト最小化（迷路）問題に帰着されます。" );
    CALL_AC( MinimisationSolvingMaze );
  } else if( num == num_temp++ ){
    CERR( "- 経由点の経由順序が指定されているならば、グラフの線形グラフに対する" );
    CERR( "  分割統治ダイクストラ法" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Double\\Errand" );
    CERR( "- 経由点の経由順序が指定されておらずかつ経由点が頂点全体ならば、HeldKarp法" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\HeldKarp" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- 最短経路の始点の特定が不要ならば、始点を１つ追加して元の始点へコスト0の" );
    CERR( "  有向辺を追加" );
    CERR( "- 最短経路の始点の特定が必要ならば、辺を反転" );
    CERR( "により１始点多終点コスト最小コスト化（迷路）問題に帰着されます。" );
    CALL_AC( MinimisationSolvingMaze );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationCoveringSize );
  } else if( num == num_temp++ ){
    CERR( "数直線上の始点と終点の組み分けに関する距離の総和の最小化を考えます。" );
    CERR( "始点と終点を合わせてソートして小さい順に走査し、余りの個数ごとに" );
    CERR( "コストの最小値を管理する動的計画法を検討しましょう。" );
    CERR( "\\Mathematics\\Geometry\\AffineSpace\\Distance\\L1\\CompleteBipartiteMatching" );
  } else if( num == num_temp++ ){
    CERR( "各終点tjをゴールとして良い人数の上限をNjと置いて" );
    CERR( "- 各辺の容量を∞に設定" );
    CERR( "- 各始点siへ容量1コスト0の辺を持つ頂点Sを追加" );
    CERR( "- 各終点tjから容量Njコスト0の辺を持つ頂点Tを追加" );
    CERR( "とすることで得られる有無向グラフに対しPrimal-Dual法を適用しましょう。" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Algorithm\\MinimumCostFlow" );
  } else if( num == num_temp++ ){
    CALL_AC( NearestNeighbour );
  }
  CERR( "" );
  CERR( "点の座標と最小化すべきコスト以外の数値xに変化がある場合、最小コスト移動に" );
  CERR( "おいてxの動く範囲を絞って点の座標とxの組を頂点とするグラフを考えましょう。" );
  CERR( "" );
  CERR( "重みが辺ではなく頂点についている場合" );
  CERR( "- 羃等モノイドならば特に頂点は追加せず" );
  CERR( "- 羃等でない可換モノイドならば重みが単位元である始点と終点を追加して" );
  CERR( "各辺の重みを両端の重みに演算を適用したもので定義しましょう。" );
}

AC( MinimisationSolvingMaze )
{
  ASK_YES_NO( "特定の辺群の合計使用回数に制限がありますか？" );
  if( reply == "y" ){
    CALL_AC( MinimisationSolvingMazeBoundedChoice );
  } else {
    ASK_YES_NO( "|E|が10^8オーダーで抑えられますか？" );
    if( reply == "y" ){
      CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdges );
    } else {
      CALL_AC( MinimisationSolvingMazeUnboundedChoiceManyEdges );
    }
  }
}

AC( MinimisationSolvingMazeBoundedChoice )
{
  CERR( "合計使用回数に制限のない辺たちをE_0、制限のある辺たちをE_1、" );
  CERR( "使用回数の上限をCと置きます。" );
  ASK_YES_NO( "|E_0|*(C+1)+|E_1|*Cが10^8オーダーで抑えられますか？" );
  if( reply == "y" ){
    CERR( "使用回数ごとに頂点を複製して、|V|頂点|E_0|辺の無向グラフ|C+1|個の" );
    CERR( "非輪状グラフを構成することで、合計使用回数制限のない問題に帰着できます。" );
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdges );
  } else {
    ASK_YES_NO( "C=1かつ一終点ですか？" );
    if( reply == "y" ){
      CERR( "(V,E_0)に対し始点と終点からの一始点多終点最短経路問題を解き、" );
      CERR( "各2点間をE_1で結んだ時の最短経路を2重ループやそのデータ構造高速化で" );
      CERR( "計算することで合計使用回数制限のない問題に帰着できます。" );
      CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdges );
    } else {
      CERR( "(V,E_0)に対し多始点多終点最短経路問題を解き、各2点間を１回だけE_1で" );
      CERR( "結んだ時の最短経路を2重ループやそのデータ構造高速化で計算します。" );
      CERR( "その後、その結果をMinTropicalSemirng上の|V|次正方行列に格納し、" );
      CERR( "0乗からC乗までの総minをO(V^3 C)で計算することで" );
      CERR( "合計使用回数制限のない問題に帰着できます。" );
      CALL_AC( MinimisationCoveringSize );
    }
  }
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdges )
{
  ASK_YES_NO( "演算は羃等的ですか？" );
  if( reply == "y" ){
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesIdempotent );
  } else {
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotent );
  }
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesIdempotent )
{
  CERR( "コスト上限をCと置きます。" );
  ASK_YES_NO( "マルチクエリですか？" );
  if( reply == "y" ){
    CERR( "クエリ回数をQと置きます。" );
    CERR( "- O(E α(V + log_2 E) + QV)" );
    CERR( "  が間に合いそうならばクラスカル法で最小全域木に帰着" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFind\\Kruscal" );
    CERR( "- O((V + (E + Q)α(V) + min(C,Q log_2 Q))log_2 E)" );
    CERR( "  が間に合いそうならばコストで辺をソートしてUnionFind並列二分探索" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFind\\ParallelBinarySearch" );
    CERR( "- そうでなく始点が共通ならば、シングルクエリの解法で多終点並列計算" );
    CERR( "- そうでないならば、シングルクエリの解法をQ回反復" );
    CERR( "を検討しましょう。" );
    CERR( "" );
    CERR( "以下、シングルクエリの解法を説明します。" );
  }
  CERR( "- O(min(V^2,(V+E)log_2 E))が間に合いそうならばダイクストラ法" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
  CERR( "- O((V+E)C)が間に合いそうならばコスト最大値も状態に含めたグラフ上での" );
  CERR( "  幅優先探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearchSearch" );
  CERR( "- O(V + E(log E + α(V)))が間に合いそうならば" );
  CERR( "  コストで辺をソートしてUnionFind" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFind" );
  CERR( "- O(V + Eα(V + log_2 E)))が間に合いそうならば" );
  CERR( "  クラスカル法で最小全域木まで辺を削減してBFS/DFS＋経路復元" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFind\\Kruscal" );
  CERR( "- Gがグラフの非輪状グラフならば" );
  CERR( "  - O(min(sum_i V_i^2,sum_i((V_i+E_i)log_2 E_i))が間に合いそうならば" );
  CERR( "    分割統治ダイクストラ法" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Double" );
  CERR( "  - 間に合わなさそうならば分割統治を動的計画法で書き直しデータ構造高速化" );
  CERR( "- 辺のコストのうちK番目に大きい値の最小化でO((V+E)log C)が間に合いそう" );
  CERR( "  ならば、コストcを決め打って辺の新たな重みとして「コストがcより大きい」の" );
  CERR( "  真偽を考えて01幅優先探索を行い、経路の重みの総和の最小値がK未満である" );
  CERR( "  ようなcの最小値を二分探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BFS\\01" );
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotent )
{
  ASK_YES_NO( "コストは負になりえますか？" );
  if( reply == "y" ){
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotentNegative );
  } else {
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotentNonNegative );
  }
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotentNegative )
{
  CERR( "- O(VE)が間に合いそうならば、ベルマンフォード法" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BellmanFord" );
  CERR( "- マルチクエリで辺の削除を行いO(VE+Q(V+E)log_2 E)が間に合いそうならば" );
  CERR( "  ベルマンフォード法によるポテンシャル前計算＋ポテンシャル付きダイクストラ法" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Potentialised\\BellmanFord" );
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotentNonNegative )
{
  ASK_YES_NO( "マルチクエリですか？" );
  if( reply == "y" ){
    CERR( "クエリ回数をQと置きます。" );
    CERR( "- O(V^3 + Q)が間に合いそうならばワーシャルフロイド法" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\FloydWarshall" );
    CERR( "- そうでなく始点が共通ならば、シングルクエリの解法で多終点並列計算" );
    CERR( "- そうでないならば、シングルクエリの解法をQ回反復" );
    CERR( "を検討しましょう。" );
    CERR( "" );
    CERR( "以下、シングルクエリの解法を説明します。" );
  }
  CERR( "- コストが1のみかつO(V+E)が通りそうならば、幅優先探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "- そうでなくコストが{0,1}値かつO(V+E)が通りそうならば、01幅優先探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\ZeroOne" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "- そうでないならばコスト総和上限をCとし、" );
  CERR( "  - O(min(V^2,(V+E)log_2 E))が間に合いそうならばダイクストラ法" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
  CERR( "  - O((V+E)C)が間に合いそうならば、コスト総和も状態に含めたグラフ上" );
  CERR( "    での幅優先探索" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearchSearch" );
  CERR( "  - Gがグラフの非輪状グラフならば" );
  CERR( "    - O(min(sum_i V_i^2,sum_i((V_i+E_i)log_2 E_i))が間に合いそう" );
  CERR( "      ならば分割統治ダイクストラ法" );
  CERR( "      \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Double" );
  CERR( "    - 間に合わなさそうならば、分割統治を動的計画法で書き直しデータ構造高速化" );
}

AC( MinimisationSolvingMazeUnboundedChoiceManyEdges )
{
  CERR( "- 各操作をデータ構造に翻訳することでシンプルな最小化問題に帰着" );
  CERR( "  - 区間加算ならば、階差数列の２点加算に翻訳" );
  CERR( "  - 部分木の白黒反転ならば、木上の階差数列の１点更新に翻訳" );
  CERR( "  - 無向グラフと非輪状有向グラフの合成ならば、有向グラフの有向辺に沿った" );
  CERR( "    動的計画法のデータ構造高速化" );
  CERR( "- 操作を選択部分（どこを操作するか、など）と決定的遷移" );
  CERR( "  （選択部分を決めたら最小コストを実現するために自動的に決まる部分）" );
  CERR( "  に分け、選択部分の全探索や半分全列挙" );
  CERR( "  - 例えば各成分高々１回しか操作しないことが最適であれば、" );
  CERR( "    どの成分を操作するかに対応する部分集合の探索問題。" );
  CERR( "  - 例えば区間選択の代わりに始切片選択のみで済むならば、" );
  CERR( "    どの始切片を操作するかに対応する部分集合の探索問題。" );
  CERR( "- 操作前後で不変な値（総和や白黒の個数差mod2など）があれば、" );
  CERR( "  操作を何らかの零化問題に翻訳。" );
  CERR( "  - なるべくコストを簡単で等価な値に翻訳し、その翻訳に則って操作も更に翻訳し、" );
  CERR( "    よりシンプルな（例えば貪欲法が適用可能な）零化問題への帰着" );
  CERR( "  - 例えば経路を摂動する方法であってコストが大きくならないものを特定し、" );
  CERR( "    摂動可能でない経路のみに絞ることでEを削減" );
  CERR( "- 半順序集合上の操作ならば、到達可能領域Aの形状から最小コストの上界を計算" );
  CERR( "  - 各p in Aに対しpの始切片がAに含まれるならば、最小コストの上界として" );
  CERR( "    終点の上界に登ってから降りる経路のコストを計算" );
  CERR( "  - 最小コストの上界が実際に最小であるかを、損をしない変形などで確認" );
  CERR( "検討しましょう。" );
}

AC( NearestNeighbour )
{
  CERR( "D次元ユークリッド空間内のN点を考えます。" );
  CERR( "- L^p距離に関する最近点対問題でかつexpected O(N log N)が間に合いそうならば" );
  CERR( "  kd木や空間を細分する分割統治でマージ時に枝刈り" );
  CERR( "  https://people.csail.mit.edu/indyk/6.838-old/handouts/lec17.pdf" );
  CERR( "  \\Mathematics\\Geometry\\AffineSpace\\Distance\\ANN" );
  CERR( "- D=1で１点から点群への距離の最小化問題でかつO(log N)が間に合いそうならば" );
  CERR( "  set上の２分探索" );
  CERR( "  \\Mathematics\\Geometry\\AffineSpace\\Distance" );
  CERR( "- D=1で点群から点群への距離の最小化問題でかつO(N log N)が間に合いそうならば" );
  CERR( "  ソートして左右から踏査" );
  CERR( "  \\Mathematics\\Geometry\\AffineSpace\\Distance" );
  CERR( "- D=2でx軸上の点群から点群へのL^1距離の最小化問題でかつO(N log N)が" );
  CERR( "  間に合いそうならばx座標でソートして左右から累積min計算" );
  CERR( "  \\Mathematics\\Geometry\\AffineSpace\\Distance\\L1" );
  CERR( "- ハイブリッド距離ならば距離の変化点で場合分けをして、それぞれに対する" );
  CERR( "  最小化問題に帰着" );
  CERR( "- グラフにより与えられる距離で経路上に（N点の外にあるかもしれない）経由点群" );
  CERR( "  が存在するならば経由点群からの距離の最小化問題に帰着" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationMovingDistance )
{
  ASK_NUMBER(
	     "１始点多終点距離最長化（最遠点探索）問題" ,
	     "多始点多終点距離最長化（最長歩道探索）問題" ,
             "最遠点問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( MaximisationMovingDistanceSingleStart );
  } else if( num == num_temp++ ){
    ASK_YES_NO( "閉路を持たない有向グラフですか？" );
    if( reply == "y" ){
      CERR( "トポロジカルソートによる動的計画法" );
      CERR( "\\Mathematics\\Geometry\\Graph\\TopologicalSort" );
    } else {
      CERR( "始点を全探策することで、１始点多終点コスト最大化問題に帰着されます。" );
      CALL_AC( MaximisationMovingDistanceSingleStart );
    }
  } else if( num == num_temp++ ){
    CERR( "D次元空間の点群SとTに対しmax_{s in S} sum_{t in T} d(s,t)" );
    CERR( "を考えます。Sの要素数をN、Tの要素数をMとします。" );
    CERR( "- L^∞距離ならば、" );
    CERR( "  - D=1ならば、" );
    CERR( "    - ユークリッド空間でかつO(N+M)が間に合いそうならば、sの座標の" );
    CERR( "      最小値と最大値を前計算しそれらでの値のうち大きい方を求める" );
    CERR( "    - トーラスでかつO((N+M)log(N+M))が間に合いそうならば、sの座標を" );
    CERR( "      動かした時のd(s,t)のグラフが傾き-1,0,+1のいずれかであることに" );
    CERR( "      注目して傾きの変化点の候補とsの座標を優先度付きキューで管理する" );
    CERR( "      イベント走査" );
    CERR( "      - Sが全体ならばsの座標の管理は不要" );
    CERR( "      - 傾きの変化点の候補はO(M)個なのでoff-by-oneの考察は避け、" );
    CERR( "        実際に傾きを実行時に計算するようにする" );
    CERR( "  - D>1ならば、成分ごとに見て1次元に帰着させて答えの最大値を求める" );
    CERR( "- L^1距離ならば、" );
    CERR( "  - D=1ならばL^∞距離と同じ" );
    CERR( "  - D>1ならば、" );
    CERR( "    - Sが直積ならば、成分ごとに見て1次元に帰着させて答えの総和を求める" );
    CERR( "    - D=2でユークリッド空間でO(N+M)が間に合いそうならば、" );
    CERR( "      45度回転で2次元L^∞距離に帰着" );
    CERR( "    - D>2ユークリッド空間でO(2^D(N+M))が間に合いそうならば、" );
    CERR( "      s-tの符号全探策をして符号を決め打つごとに1次元" );
    CERR( "      （sの線形和とtの線形和の距離）に帰着" );
  }
  CERR( "を検討しましょう。" );
}

AC( MaximisationMovingDistanceSingleStart )
{
  CERR( "- コストが非正でO((V+E)log_2 E)が間に合いそうならば-1倍してダイクストラ法" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
  CERR( "- コストが正になりえてO(VE)が間に合いそうならば1倍してベルマンフォード法" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BellmanFord" );
  CERR( "- コストが1で無向グラフとして完全な有向グラフでO(V log V)が間に合いそうならば" );
  CERR( "  Vに関する再帰的構成" );
  CERR( "  https://yukicoder.me/submissions/916203" );
}

AC( MaximisationFunctionOnArray )
{
  ASK_NUMBER(
	     "問題文または入力で与えられる１個の配列Aに関する問題" ,
	     "問題文または入力で与えられる複数の配列A_0,A_1,...に関する問題" ,
	     "条件を満たす任意の配列に関する問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnOneArray );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnMultipleArray );
  } else if( num == num_temp++ ){
    CERR( "関数をfと置き、条件Pを満たす配列aをわたる値f(a)の最大値を考えます。" );
    CERR( "最小値は-fを考えることで最大値に帰着されます。" );
    CERR( "- 取り得る値が少なくf(a)がaの長さに関して再帰的構造を持つ場合は、" );
    CERR( "  「長さiの時に可能な値全体または一部の集合dp[i]」" );
    CERR( "  を管理するiに関する動的計画法" );
    CERR( "- 「fがv以上の値を取り得るか否か」が判定可能である時は" );
    CERR( "  vに関する二分探索" );
    CERR( "- 何らかの不変量g(a)をyに固定した時のf(a)の最大値F(y)が計算可能" );
    CERR( "  ならば、yを動かしてF(y)の最大化をする分割統治法" );
    CERR( "を検討しましょう。" );
  }
}

AC( MaximisationFunctionOnOneArray )
{
  CALL_AC( SortingArray );
  ASK_NUMBER(
             "Aの分割（部分和、区間和、補集合）に関する問題" ,
             "Aの変更後に配列を受け取る関数に代入した値の最大／最小化問題"
             );
  if( num == num_temp++ ){
    CALL_AC( MinimisationPartitionOfArray );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationArrayFunction );
  }  
}

AC( SortingArray )
{
  CERR( "ソートしても答えが変わらないならば適宜ソートしましょう。" );
  CERR( "成分を受け取る関数fを１つだけ考える際は予めAの各成分にfを" );
  CERR( "適用した配列f circ AでAを置き換えて考えます。" );
}

AC( MaximisationFunctionOnMultipleArray )
{
  ASK_NUMBER(
             "A_0の部分和とA_1の補部分和の最大／最小化問題" ,
             "A_iの部分和と関数f_iの積のiをわたる総和の最大／最小化問題" ,
             "各iごとにj_iを１つ選んで得られる(A_{j_i,i})_iの価値最大化問題" ,
             "max_i max_j f(a_i,b_j)などの計算問題" ,
             "その他の問題"
             );
  if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnTwoArray );
  } else if( num == num_temp++ ){
    CERR( "与えられる配列の個数をM個とし、積順序に関して順序保存である関数" );
    CERR( "f_0,f_1,...:N^{M-1}->Nが与えられ、" );
    CERR( "  (sum_{i in S_0} A_0[i]) f_0(#S_1,#S_2...)" );
    CERR( "+ (sum_{i in S_1} A_1[i]) f_1(#S_0,#S_2,...)" );
    CERR( "+ ..." );
    CERR( "を最大化する部分集合の列(S_0,S_1,...)を考えます。" );
    CERR( "最小化の場合は-fを考えます。" );
    CERR( "" );
    CERR( "A_0,A_1,...はそれぞれ昇順にソートしても良く、S_0,S_1,...は" );
    CERR( "終切片に限っても一般性を失いません。S_0,S_1,...,S_{M-2}を" );
    CERR( "決め打ち全探策しS_{M-1}の最適解を二分探索で求めましょう。" );
  } else if( num == num_temp++ ){
    CERR( "項目iの価値の選択肢が複数種類あるコストなしナップサック問題" );
    CERR( "を考えましょう。" );
    CALL_AC( SingleKnapsackCostfreeMultiValue );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionDoubleSumNonQuotient );
  } else if( num == num_temp++ ){
    CERR( "A_0,A_1,...を結合して１つの配列とみなします。" );
    CALL_AC( MaximisationFunctionOnOneArray );
  }
}

AC( MaximisationFunctionOnTwoArray )
{
  CERR( "(sum_{i in S} A_0[i])+(sum_{i in S^c} A_1[i])を最大化する" );
  CERR( "部分集合Sを求めます。最小化はA_0,A_1を-1倍すれば良いです。" );
  CERR( "- Sの要素数に制限がないならば、sum_i max(A_0[i],A_1[i])" );
  CERR( "- Sの要素数がKで固定ならば、A_0[i]-A_1[i]を大きい順にK個" );
  CERR( "  足したものとA_1の総和の和" );
  CERR( "が求める最大値です" );
}

AC( Knapsack )
{
  CERR( "総和を取る値を価値と呼ぶことにします。" );
  CERR( "配列の項数N、第i成分の価値A_i、価値の総和の上限Vとします。" );
  CERR( "{0,...,N-1}の部分集合または集合として含まれる多重集合Iであって、" );
  CERR( "- sum(i in I){A_i} = v" );
  CERR( "- その他の条件" );
  CERR( "を満たすものが存在するv <= Vの最大化を考えます。" );
  CERR( "" );
  CERR( "コストの総和上限Cとします。コストの半順序モノイドにおけるC以下の元" );
  CERR( "全体の集合の要素数を|C|と置きます。" );
  ASK_NUMBER(
	     "Iを始切片に限る場合" ,
	     "そうでなくIを区間に限る場合" ,
	     "そうでなくIの連結成分長に上限がある場合" ,
	     "そうでない場合"
	     );
  if( num == num_temp++ ){
    CALL_AC( KnapsackInitialSegment );
  } else if( num == num_temp++ ){
    CALL_AC( KnapsackInterval );
  } else if( num == num_temp++ ){
    CALL_AC( KnapsackBoundedIntervalLength );
  } else {
    CALL_AC( KnapsackSubset );
  }
}

AC( KnapsackInitialSegment )
{
  CERR( "コスト(W_i)_iの部分和で表せないコスト全体の集合の上限をLとします。" );
  CERR( "- 例えばW_i=i^2ならば、L=128です。" );
  CERR( "  https://oeis.org/A001422" );
  CERR( "- 例えばW_i=p(i+n)ならば、LはKlove数列" );
  CERR( "  (6,9,27,45,45,57,75,81,87,105,...)の第n項です。" );
  CERR( "  \\Mathematics\\Arithmetic\\Prime\\KloveSequence" );
  CERR( "  https://oeis.org/A007414" );
  ASK_YES_NO( "ナップサックは１つですか？" );
  CERR( "価値が非負ならば、先頭から何項選べるかさえ分かれば価値が求まるので、" );
  CERR( "価値をコストに置き換えたナップサック問題、すなわち" );
  CERR( "コストを価値とするコストなし価値上限つきナップサックを考えます。" );
  if( reply == "y" ){
    CALL_AC( KnapsackInitialSegmentSingleKnapsack );
  } else {
    CALL_AC( KnapsackInitialSegmentDoubleKnapsack );
  }
}

AC( KnapsackInitialSegmentSingleKnapsack )
{
  CERR( "- (W_i)_iの累積和を愚直に計算していき、Lを超えない最大の項数を計算" );
  CERR( "- (W_i)_iの累積和を式変形で明示的に求め、Lを超えない最大の項数を二分探索" );
  CERR( "を検討しましょう。" );
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\Costfree\\InitialSegment" );
}

AC( KnapsackInitialSegmentDoubleKnapsack )
{
  CERR( "ナップサックが２つであるとし、それらのコスト上限をそれぞれC_1 <= C_2とし、" );
  CERR( "(W_i)_iが昇順であるとします。" );
  CERR( "- 各非負整数nに対しs_n := sum_{i=0}^{n} W_iと置き、" );
  CERR( "- W_n > 2Lを満たす最小のnをN_1と置き、" );
  CERR( "- s_n > C_1を満たす最小のnをN_2と置き、" );
  CERR( "- W_n > C_1を満たす最小のnをN_3と置きます。" );
  CERR( "選択する項目全体の集合が始切片でなければならないことから、" );
  CERR( "- N_1 <= N_2ならば、s_{N_2+1}-s_{N_2} = W_{N_2} > 2Lより" );
  CERR( "  max(s_{N_2+1}-C_1,C_1-s_{N_2}) > LなのでN_2+1までの項目を" );
  CERR( "  うまく組み合わせてC_1が表せるため、コスト総和上限CがC_1 + C_2で" );
  CERR( "  ナップサックが１つの場合に帰着" );
  CERR( "- N_1 > N_2ならば、N_3未満の各iに対する項iのみを選択する設定で可能な" );
  CERR( "  選択全体を考えた時のナップサック１のみのコストの最大値をC_1'と置くと、" );
  CERR( "  N_3以上のiに対する項iはナップサック２にしか入らないため、" );
  CERR( "  コスト総和上限CがC_1' + C_2でナップサックが１つの場合に帰着" );
  CERR( "を検討しましょう。以下ナップサックが１つの場合を考えます。" );
  CALL_AC( KnapsackInitialSegmentSingleKnapsack );
}

AC( KnapsackInterval )
{
  ASK_NUMBER(
             "区間長が固定の問題" ,
             "区間に属すべき点が与えられるクエリ処理" ,
             "コストありの区間和最大化" ,
             "コストなしの区間和最大化" ,
             "コストなしの区間和の絶対和最大化"
             );
  if( num == num_temp++ ){
    CERR( "区間をスライドしていき、両端の更新値を用いて最大値を管理しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "属すべき点の両側で始切片和と終切片和の最小値の総和を求め全体の総和から" );
    CERR( "引けばよいので、始切片和の始切片最小値と終切片和の終切片最小値を" );
    CERR( "前計算しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "尺取り法で区間を伸ばし両端の更新値を用いて最大値を管理しましょう。" );
    CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\Interval" );
  } else if( num == num_temp++ ){
    CERR( "区間和最大化は、区間の右端を固定した最大値を管理する動的計画法" );
    CERR( "を検討しましょう。" );
    CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\Interval\\Costfree" );
    CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\Interval\\Costfree\\UnboundedValueSum" );
  } else if( num == num_temp++ ){
    CALL_AC( KnapsackIntervalSumAbsoluteSum );
  }
}

AC( KnapsackIntervalSumAbsoluteSum )
{
  CERR( "価値の配列全体をK個以下の区間に分割した時の区間和の絶対和の最大化は、" );
  CERR( "絶対値を±1倍の最大値として処理しKに関する再帰を検討しましょう。" );
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\Interval\\Costfree\\AbsolutePartition" );
}

AC( KnapsackBoundedIntervalLength )
{
  CERR( "Iの各連結成分の長さの上限がLであるとします。選択する項目の価値総和の最大化は" );
  CERR( "選択しない価値総和の最小化に帰着されるので、N未満の各iに対し、" );
  CERR( "dp[i] = 「[0,i)で選択しない項目の価値総和の最小値」" );
  CERR( "と定め、漸化式" );
  CERR( "dp[i+L] = (min_{j=i}^{i+L-1} dp[j]) + A[i+L]" );
  CERR( "を" );
  CERR( "- O(N log N)が間に合いそうならば、IntervalMinBITによる一点min更新と" );
  CERR( "  区間min取得" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
  CERR( "- O(N log L)が間に合いそうならば、map<値,個数>による直近L個の管理" );
  CERR( "で高速化することでiに関する動的計画法を処理しましょう。" );
}

AC( KnapsackSubset )
{
  ASK_YES_NO( "ナップサックは１つですか？" );
  if( reply == "y" ){
    CALL_AC( SingleKnapsack );
  } else {
    CALL_AC( MultipleKnapsack );
  }
}

AC( SingleKnapsack )
{
  ASK_YES_NO( "各項目が複数回選択できますか？" );
  if( reply == "y" ){
    CALL_AC( SingleKnapsackMultipleChoice );
  } else {
    CERR( "最小費用流はコストに流量が掛かるためこの設定では適用できないことに" );
    CERR( "注意してください。" );
    CALL_AC( SingleKnapsackSingleChoice );
  }
}

AC( SingleKnapsackMultipleChoice )
{
  ASK_YES_NO( "各項が無制限に選択できますか？" );
  if( reply == "y" ){
    CALL_AC( SingleKnapsackUnboundedChoice );
  } else {
    CERR( "各項の選択回数の上限をHと置きます。" );
    ASK_YES_NO( "負の価値も許容されますか？" );
    if( reply == "y" ){
      CALL_AC( SingleKnapsackBoundedChoiceNegativeValue );
    } else {
      ASK_YES_NO( "コストがありますか？" );
      if( reply == "y" ){
	CALL_AC( SingleKnapsackBoundedChoiceUnstableCost );
      } else {
	CALL_AC( SingleKnapsackBoundedChoiceCostfree );
      }
    }
  }
}

AC( SingleKnapsackUnboundedChoice )
{
  ASK_YES_NO( "コストがありますか？" );
  if( reply == "y" ){
    CERR( "- 各項のコストが不変であるならば、" );
    CERR( "  - O(N + |C|^2)が通りそうならば、" );
    CERR( "   「コストcの項の価値の最大値v[c]」" );
    CERR( "    を前計算し" );
    CERR( "   「コストの総和がc以下の時の価値の最大値dp[c]」" );
    CERR( "    を管理するcに関する動的計画法" );
    CERR( "    \\Mathematics\\Combinatorial\\KnapsackProblem\\UnboundedChoice\\NegativeValue" );
    CERR( "  - O(sum_i A_i * max_i C_i)が間に合いそうならば" );
    CERR( "    単位価値辺りのコストが最小の項以外の項の選択回数に上限が" );
    CERR( "    つくことを利用して上限付きの設定に帰着" );
    CERR( "    \\Mathematics\\Combinatorial\\KnapsackProblem\\UnboundedChoice" );
    CERR( "  - コストが多次元ならば、コストベクトル(W_i)_iと直交する" );
    CERR( "    整数係数ベクトルを用いて変数決め打ち全探策" );
    CERR( "    参考：https://yukicoder.me/problems/no/2309/editorial" );
    CERR( "を検討しましょう。" );
  } else {
    CERR( "- O(N + V^2)が通りそうならば、" );
    CERR( " 「i個目までの項を使って価値の総和がvの時のコストの最小値dp[i][v]」" );
    CERR( "  を管理するi,vに関する動的計画法" );
    CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\UnboundedChoice\\Costfree" );
    CERR( "を検討しましょう。" );
  }
  CERR( "" );
  CERR( "コストから選択回数上限を設定することで選択回数上限つきの問題に" );
  CERR( "帰着されることも可能です。" );
  CERR( "" );
  if( reply == "y" ){
    CALL_AC( SingleKnapsackBoundedChoiceUnstableCost );
  } else {
    CALL_AC( SingleKnapsackBoundedChoiceCostfree );
  }
}

AC( SingleKnapsackBoundedChoiceNegativeValue )
{
  CERR( "- O(N min(|C|,H 2^{N/2}) log_2 H)が通りそうならば" );
  CERR( "  重複回数を二進法で分解してまとめ、重複がない場合に帰着させましょう、" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Boundedchoice\\NegativeValue" );
  CALL_AC( SingleKnapsackSingleChoice );
}

AC( SingleKnapsackBoundedChoiceUnstableCost )
{
  CERR( "S回目の選択以降コストが定数になるとして、O(N S |C|)が通りそうならば" );
  CERR( " 「i個目までの項を使ってコストの総和がc以下の時の価値の最大値dp[i][c]」" );
  CERR( "  を管理するi,cに関する動的計画法" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\BoundedChoice\\Unstable" );
  CERR( "を検討しましょう。" );
}

AC( SingleKnapsackBoundedChoiceCostfree )
{
  CERR( "価値をコストとみなしてコストがある場合に帰着させましょう。" );
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\BoundedChoice\\Costfree" );
}

AC( SingleKnapsackSingleChoice )
{
  CERR( "i選択目の項目のコスト上限（存在しない場合∞）をC_iと置きます。" );
  ASK_NUMBER(
             "コストが1である問題" ,
             "コストが1とは限らない問題" ,
             "コストがない問題"
             );
  if( num == num_temp++ ){
    CALL_AC( SingleKnapsackCostOne );
  } else if( num == num_temp++ ){
    CERR( "最大流はコストがない場合にしか適用できないことに注意してください。" );
    ASK_YES_NO( "C_iはiに依存しない値ですか？" );
    if( reply == "y" ){
      CALL_AC( SingleKnapsackUnordered );
    } else {
      CERR( "各選択をそれぞれ別のナップサックとみなすことで、項を１つだけ格納できる" );
      CERR( "ナップサックが複数ある場合に帰着されます。" );
      CALL_AC( MultiKnapsackCostBoundSetting );
      CALL_AC( MultipleKnapsackSingleItem );
    }
  } else {
    CALL_AC( SingleKnapsackCostfree );
  }
}

AC( SingleKnapsackCostOne )
{
  CERR( "O(N log min(N,sup_i C_i))が間に合いそうならば、iの小さい順に" );
  CERR( "i番目までの正の価値を上からC_i個まで優先度付きキューで管理して" );
  CERR( "総和を取れば良いです。" );
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\CostOne" );
}

AC( SingleKnapsackUnordered )
{
  ASK_YES_NO( "根付き木の根を含む連結部分集合を選択する問題ですか？" );
  if( reply == "y" ){
    CERR( "線形グラフの場合を考え、その解法を深さ優先探索に一般化しましょう。" );
    CERR( "以下線形グラフとします。" );
    CERR( "" );
  }
  CERR( "コストまたは価値でソートしても構いません。" );
  ASK_YES_NO( "コストが１次元ですか？" );
  CERR( "- O(N 2^N)が通りそうかつコストの動く範囲が遷移途中も制限されているならば、" );
  CERR( "  P(N)のハッセ図を幅優先探策" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Restrictive" );
  CERR( "- O(N 2^{N/2})が通りそうならば半分全列挙" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative" );
  CERR( "- O(N |C|)が通りそうかつコストが非負ならば、" );
  CERR( "  dp[i][c]=「i番目の項まで使ってコスト総和がcの時の価値総和最大値」" );
  CERR( "  を管理するi,cに関する動的計画法" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Value" );
  if( reply == "y" ){
    CALL_AC( SingleKnapsackWithLinearCost );
  } else {
    CALL_AC( SingleKnapsackWithMultiCost );
  }
}

AC( SingleKnapsackWithLinearCost )
{
  CERR( "  - |C|が大きい時はコスト降順にソートして" );
  CERR( "    dp[i][c]=「i番目の項まで使ってコスト総和がc以下の時の価値総和最大値」" );
  CERR( "    をcに関するmapで管理するiに関するnext DPで、keyの最大値から" );
  CERR( "    残りのコスト総和を引いた値未満のkeyを枝刈り" );
  CERR( "  - 特にコストが指数オーダーで変化するならば、" );
  CERR( "    「ある項目を選ばないならば、適切な終切片が選択可能」" );
  CERR( "    という考察による選択肢の絞り込み" );
  CERR( "- O(N V)が通りそうかつ価値が非負ならば、" );
  CERR( "  dp[i][c]=「i番目の項まで使って価値総和がvの時のコスト総和最小値」" );
  CERR( "  を管理するi,vに関する動的計画法" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Cost" );
  CERR( "  - Vが大きい時は価値降順にソートして" );
  CERR( "    dp[i][c]=「i番目の項まで使って価値総和がv以下の時のコスト総和最小値」" );
  CERR( "    をvに関するmapで管理するiに関するnext DPで、keyの最大値から" );
  CERR( "    残りの価値総和を引いた値未満のkeyを枝刈り" );
  CERR( "  - 特に価値が指数オーダーで変化し良い漸化式を満たすならば、" );
  CERR( "    「keyの最大値-keyの短い始切片の部分和の形のkeyのみ考えれば良い」" );
  CERR( "    という考察による選択肢の絞り込み" );
  CERR( "    https://yukicoder.me/problems/no/2167/editorial" );
  CERR( "を検討しましょう。" );
}

AC( SingleKnapsackWithMultiCost )
{
  CERR( "- C=[0,W]^DでO(N W + W^{D-1}(D + log(1+W)))が通りそうかつ" );
  CERR( "  各コストが１つしか非自明成分を持たないならば、" );
  CERR( "  １つしか非自明成分を持たないコストごとに価値の最大値を求めて区間MaxBIT" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Value\\Multicost" );
  CERR( "を検討しましょう。" );
}

AC( SingleKnapsackCostfree )
{
  ASK_YES_NO( "各項目に複数種類の価値があり１つの価値を選択する問題ですか？" );
  if( reply == "y" ){
    CALL_AC( SingleKnapsackCostfreeMultiValue );
  } else {
    CALL_AC( SingleKnapsackCostfreeSingleValue );
  }
}

AC( SingleKnapsackCostfreeMultiValue )
{
  CERR( "途中まで選択した時点で次以降に選択できる価値全体に共通の性質を抽象化します。" );
  ASK_NUMBER(
             "問題で最初に与えられた選択肢の部分集合から１つ選ぶ" ,
             "これまでの価値総量をアフィン変換した値を次の項目の価値とする" ,
             "これ以降のいくつかの項目の価値を加算更新する"
             );
  if( num == num_temp++ ){
    CERR( "部分集合を決定するデータをdとして" );
    CERR( "dp[i][d] = i項目目まで選択を終えた時にデータがdである時の最大価値" );
    CERR( "を管理する動的計画法を検討しましょう。" );
    CERR( "漸化式はデータの遷移d->d'において可能な選択肢の中で価値の最大値v[d][d']を" );
    CERR( "加算すれば良く、そのためにはv[d][d']も高速に計算できるようにすると良いです。" );
  } else if( num == num_temp++ ){
    CERR( "- アフィン変換の一次係数が非負であれば、毎回の選択後の価値を最大にする" );
    CERR( "  貪欲法" );
    CERR( "- アフィン変換の一次係数が負になりえるのであれば、毎回の選択後の価値の" );
    CERR( "  最大値と最小値を両方管理する動的計画法" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "項目iの価値をv_i、加算更新値をb_iとすると、加算更新を受ける項目の" );
    CERR( "選択数c_iを用いて項目iの価値総量への寄与はv_i+b_i*c_iと表せます。" );
    CERR( "dp[i][c_{i+1}たちを算出するために必要なデータ]" );
    CERR( "=データに従って項目iまで選んだ時のv_i+b_i*c_iたちの最大値の総和" );
    CERR( "を管理するiなどに関する動的計画法を検討しましょう。" );
  }
}

AC( SingleKnapsackCostfreeSingleValue )
{
  ASK_YES_NO( "各項が独立に選択できる（選択方法に罰金や報酬がない）問題ですか？" );
  if( reply == "y" ){
    CERR( "- O(N 2^{N/2})が通りそうならば半分全列挙" );
    CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Costfree" );
    CERR( "- O(N v_max)が通りそうかつ非負ならば[V-v_max,V+v_max]での実現可能性を" );
    CERR( "  管理する動的計画法" );
    CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Costfree" );
    CERR( "- O((N+V)log_2 V)が通りそうかつ非負かつVが10^5オーダーでプロス素数Pを" );
    CERR( "  法とするならば法Pでの高速フーリエ変換によるexp(logの総和)計算" );
    CERR( "  \\Mathematics\\Polynomial\\Truncate" );
    CERR( "- 各始切片ごとに要素数Kの部分集合の価値の最大化をするとして" );
    CERR( "  O(N log_2 K)が通りそうならば優先度付きキューでK番目までの要素管理" );
    CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Costfree\\FixedSize" );
  } else {
    CERR( "報酬は全部得た上で、実際にはもらえない報酬を差し引く罰金形式に" );
    CERR( "翻訳し、その上で価値や依存関係や罰金を非負容量の有向辺に翻訳し、" );
    CERR( "最小カット計算に帰着させましょう。" );
    CERR( "対応するグラフの頂点数をN、辺の本数をM、流量上限をFと置きます。" );
    CERR( "- O(N 2^N)が通りそうならばbit全探索" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirstSearch\\BitExhausiveSearch" );
    CERR( "- O(min(N^2,F)M)が間に合いそうならば最大流計算によるPSP" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\MaximumFlow\\ProjectSelectionProblem" );
  }
  CERR( "を検討しましょう。" );
}

AC( MultipleKnapsack )
{
  CALL_AC( MultiKnapsackCostBoundSetting );
  ASK_YES_NO( "各ナップサックに格納できる項は高々１個ですか？" );
  if( reply == "y" ){
    CALL_AC( MultipleKnapsackSingleItem );
  } else {
    ASK_YES_NO( "項目ごとに許容するナップサックが違いますか？" );
    if( reply == "y" ){
      CALL_AC( MultipleKnapsackRestrictedMatching );
    } else {
      CALL_AC( MultipleKnapsackFreeMatching );
    }
  }
}

AC( MultiKnapsackCostBoundSetting )
{
  CERR( "ナップサックの個数をKと置き、1 <= k <= K個目のナップサックの" );
  CERR( "コスト上限をD_kとします。" );
}

AC( MultipleKnapsackSingleItem )
{
  ASK_YES_NO( "どのナップサックに格納するかによって個々の項のコストが変動しますか？" );
  if( reply == "y" ){
    CALL_AC( MultipleKnapsackSingleItemUnstableCost );
  } else {
    CALL_AC( MultipleKnapsackSingleItemStableCostUnstableCostBound );
  }
}

AC( MultipleKnapsackSingleItemUnstableCost )
{
  CERR( "|C|=∞とし、項iのコストが取りうる値をC_{i,1},C_{i,2}の2通りとし、" );
  CERR( "k個目のナップサックに格納する際の項iのコストがiに依存しない数" );
  CERR( "1 <= m_k <= 2を用いてC_{i,m_k}と表せるとします。" );
  CERR( "つまりC_{i,m_k} <= D_kが項iの選択制約です。ただし" );
  CERR( "(C_{i,1})_i,(C_{i,2})_iを入れ替えm_1 = 1としても一般性を失いません。" );
  CERR( "" );
  CERR( "O((N log_2 N)+K)が間に合いそうならば、(C_{i,m},i)_iの辞書順ソートを" );
  CERR( "sC(m)、(m_k,D_k,k)_kの辞書順ソートを(m_{k_j},D_{k_j},k_j)_jと置き、" );
  CERR( "1 <= j <= Kを小さい順に探索し、sC(m_{k_j})を用いて選択可能な項iに対する" );
  CERR( "{A_i,C_{i,2},i}をsetで管理し、その中で最大の要素を採用し、" );
  CERR( "集合から削除することでk_j個目の選択を決定しましょう。" );
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\Ordered" );
}

AC( MultipleKnapsackSingleItemStableCostUnstableCostBound )
{
  CERR( "項iのコストをC_iとします。つまりC_i<=D_kが項iの選択制約です。" );
  CERR( "" );
  CERR( "O((N log_2 N)+K)が間に合いそうならば、(C_i,i)_iの辞書順ソートをsC、" );
  CERR( "(D_k)_kの辞書順ソートを(D_{k_j})_jと置き、" );
  CERR( "1 <= j <= Kを小さい順に探索し、sCを用いて選択可能な項iに対する{A_i,i}を" );
  CERR( "setで管理し、その中で最大の要素を採用し、集合から削除することで" );
  CERR( "k_j個目の選択を決定しましょう。" );
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\Ordered" );
  CERR( "参考：https://yukicoder.me/problems/no/2422/editorial" );
}

AC( MultipleKnapsackRestrictedMatching )
{
  CERR( "各項目の価値が1であるとし、項目iをn_i個選択できるとします。" );
  CERR( "各項目が許容するナップサックの個数の総和をEと置きます。" );
  CERR( "- n_i=1でO(√(N+K)*(N+K+E))が間に合いそうならば" );
  CERR( "  項目とナップサックの最大二部マッチング" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\HopcroftKarp" );
  CERR( "- n_iが一般でO(√(N+K)*E)が間に合いそうならば" );
  CERR( "  - 始点から項目iからに流量n_i" );
  CERR( "  - 項目iから許容されるナップサックkに流量n_i" );
  CERR( "  - ナップサックkから終点に流量D_k" );
  CERR( "  を流す最大流" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\MaximumFlow" );
  CERR( "を検討しましょう。" );
}

AC( MultipleKnapsackFreeMatching )
{
  CERR( "- O(K(N 2^N + K^N))が通りそうならば、高速ゼータ変換" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Subsetwise\\Multiknapsack" );
  CERR( "- 各ナップサックの容量が非常に小さいならば、コストの大きさで項目を分けて" );
  CERR( "  コストの大きい順にそれらの選択数を全探策または二分探索" );
  CERR( "  参考：https://yukicoder.me/problems/no/2617/editorial" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationArrayFunction )
{
  CERR( "配列を受け取る関数Fが与えられているとします。与えられた配列Aに" );
  CERR( "何らかの処理をして得られる配列Bに対するF(B)の最大化問題を考えます。" );
  CERR( "最小化問題は-1倍すれば良いです。" );
  CERR( "" );
  CERR( "AのサイズNが小さい場合、操作の全探策を検討しましょう。" );
  CERR( "適宜累積和や階差数列に翻訳し直しましょう。" );
  CERR( "" );
  CERR( "操作可能な回数がNより小さい場合、操作されない成分が存在します。" );
  CERR( "操作されない成分を決め打って最大化しましょう。" );
  CERR( "" );
  CERR( "Fの終域Mの有限順序半群構造(|,R)が" );
  CERR( "(1) Rは<を含意しかつ<に関する最大元がRに関する最大元でもある。" );
  CERR( "(2) 任意のm,n in Mに対しm = m|nまたはm R m|nである。" );
  CERR( "(3) Fが|に関する総和関数である。" );
  CERR( "(4) 配列のサイズNがRの最長昇鎖列長L以下ならば、Bの|に関する累積和が" );
  CERR( "    Rに関して狭義単調増加するようにBを構成できる" );
  CERR( "を満たすならば、N>=Lの場合に求める<に関する最大値が<に関する最大元と" );
  CERR( "一致するので、N<Lの場合に帰着されます。" );
  ASK_NUMBER(
             "部分列を取り出す操作" ,
             "成分を成分の一次結合で置き換える操作" ,
             "その他の操作"
             );
  if( num == num_temp++ ){
    CALL_AC( MaximisationArrayFunctionSubsequence );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationArrayFunctionLinearCombination );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationArrayFunctionGeneralOperation );
  }
}

AC( MaximisationArrayFunctionSubsequence )
{
  CERR( "- 長さK固定の連続区間の最大値を求める問題ならば、スライド最大化" );
  CERR( "  \\Mathematics\\Combinatorial\\SlidingMinimalisation" );
  CERR( "- 始切片の要素数K固定の部分集合の総和の最大値を求める問題ならば、" );
  CERR( "  優先度付きキューによるK番目までの集合管理" );
  CERR( "  \\Mathematics\\Combinatorial\\Knapsack\\Costfree\\FixedSize" );
  CERR( "- 各長さの部分列においてソート後の隣接項の差がD以上となる個数の最小値を求める" );
  CERR( "  問題ならば、全体をソートして隣接項の差がD以上の箇所で区切り、それらの長さを" );
  CERR( "  ソートして大きい方から貪欲に選択" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CALL_AC( MaximisationArrayFunctionGeneralOperation );
}

AC( MaximisationArrayFunctionLinearCombination )
{
  CERR( "- 成分の絶対値の最小値を求める問題ならば、成分の生成するイデアルや" );
  CERR( "  成分の差が生成するイデアルに注目してgcd計算" );
  CERR( "  \\Mathematics\\Arithmetic\\Divisor\\GCD" );
  CERR( "- 隣接項の定数係数一次結合ならば、累積和に翻訳" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CALL_AC( MaximisationArrayFunctionGeneralOperation );
}

AC( MaximisationArrayFunctionGeneralOperation )
{
  CERR( "最大化すべき式のサブゴールfに表れる項xのうち決め打ちやすいものを探しましょう。" );
  CERR( "配列の長さをiで打ち切った時のxの候補数をX(i)、" );
  CERR( "配列の長さをiで打ち切ってxを決め打った時の配列の長さi+1でのxの候補数をdX(i)" );
  CERR( "と置きます。" );
  CERR( "- O(sum_i X(i) dX(i))が通りそうでfがxからO(1)で計算できるならば、" );
  CERR( "  iとxに関する動的計画法" );
  CERR( "- O(N log_2 X(N))が通りそうで" );
  CERR( "  - fがxからO(N)で計算できxに関して単調ならば、xの二分探索" );
  CERR( "  - fがxからO(N/x)で計算できるならば、xの全探索" );
  CERR( "- O(N log_2 N)が通りそうでxを並び替えるとfがxからO(log_2 N)で計算できる" );
  CERR( "  ならば、優先度つきキューなどでのxの管理" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationArrayLength )
{
  CERR( "配列のサイズをN、配列の各成分の下界の要素数の総和をE、順序集合の要素数をCと置きます。" );
  CERR( "- 全順序でO(N log_2 N)が間に合いそうならば、条件を満たす部分列の長さの最大値を" );
  CERR( "  インデックスに持つBITを用いて、それらの部分列の末尾である項を記録" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence" );
  CERR( "- 疎な半順序でO(E log_2 N)が間に合いそうならば、条件を満たす部分列の末尾を" );
  CERR( "  インデックスに持つ連想配列を用いて、それら部分列の長さの最大値を記録" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence\\Subwalk" );
  CERR( "- O(N + C^2 N^{1/2})が間に合いそうならば、順序集合の各要素c < dに対する" );
  CERR( "  「始端の値がc、終端の値がd以下である単調増加部分列の長さ」を管理する" );
  CERR( "  C次上半行列を載せたモノイド平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationFunctionOnAffineSpace )
{
  ASK_NUMBER(
	     "１変数関数の最小／最大化問題" ,
	     "１変数関数の族の最小／最大値計算" ,
	     "２変数関数の１次元への制限で得られる１変数関数の最小／最大化問題" ,
	     "距離の最小／最大化問題" ,
	     "被覆半径の最小化問題"
	     );
  if( num == num_temp++ ){
    CERR( "- 単調関数の絶対値は端点の値計算と元の関数の符号に関する二分探索" );
    CERR( "- 凸関数の最小／最大化問題は三分探索または差分の正負に関する二分探索" );
    CERR( "  \\Utility\\BinarySearch\\TernarySearch" );
    CERR( "- 可微分関数の最小／最大化問題はニュートン法" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- 一次関数の族や良い交差性を持つ関数の族はConvexHullTrick" );
    CERR( "  \\Function\\ConvexHullTrick" );
    CERR( "- グラフの上下関係の変更点を管理するイベントソート" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- f(i,j)のiを止めた最小／最大化を達成する座標jに単調性がある場合は" );
    CERR( "  iのクエリをQ個、jの候補をM個として" );
    CERR( "  - O(Q+M log Q)が間に合いそうならばMonotoneMinima" );
    CERR( "    \\Function\\MonotoneMinima" );
    CERR( "  - totally monotone性（直積で表せる部分集合への単調性の遺伝）があり" );
    CERR( "    O(Q+M)が間に合いそうならばSMAWK algorithm" );
    CERR( "    https://en.wikipedia.org/wiki/SMAWK_algorithm" );
    CERR( "- monge性を持つ行列Aの行iにおける最小化min_j A_{i,j}は単調性があるので" );
    CERR( "  上のケースに帰着" );
    CERR( "  - monge性を持つ行列に小行列として埋め込み可能な行列はmonge性を持つ。" );
    CERR( "  - kごとにmin_{i+j=k} f(i)+g(j)を求める問題でgに凸性がある場合は" );
    CERR( "    行列(f(i)+g(k-i))_{i,k}がmonge性を持つ。ただしgの定義域が" );
    CERR( "    限られている場合は凸性を保ったまま定義域を拡張する必要がある。" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "マンハッタン距離（l^1）は一次変換でl^∞に帰着させた上で、" );
    CERR( "- 単調な式に帰着できる場合、二分探索" );
    CERR( "- 最大化問題の場合、絶対値を外す符号パターンの全探策" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationCoveringSize );
  }
  CERR( "" );
  CERR( "複数のパラメータを決定すべき場合は、サブゴールの式の値を決め打ちましょう。" );
}

AC( MaximisationSubsetSize )
{
  ASK_NUMBER(
             "最大二部マッチング" ,
             "非空有限集合族の選択関数の像の最大化" ,
	     "その他の部分集合の価値最大化／コスト最初化問題" ,
	     "部分集合への分割に関する最小化問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( MaximumBipartite );
  } else if( num == num_temp++ ){
    CERR( "選択関数を添字集合から和集合への写像とみなすことで" );
    CERR( "最大二部マッチングに帰着されます。" );
    CERR( "" );
    CALL_AC( MaximumBipartite );
  } else if( num == num_temp++ ){
    ASK_YES_NO( "コストと価値の両方がありますか？" );
    if( reply == "y" ){
      CERR( "選択方法に制限付きのナップサック問題を考えましょう。" );
      CALL_AC( SingleKnapsackUnordered );
    } else {
      CERR( "コストは-1倍して価値とみなし、価値のみがある問題を考えます。" );
      ASK_YES_NO( "各要素の価値は1ですか？" );
      if( reply == "y" ){
        CALL_AC( SubsetExhusiveSearch );
        CERR( "- 半順序集合の極大鎖ならば、後続関数を定義してその逆像を辺とする" );
        CERR( "  非輪状有向グラフを構築し、極大元からの最長歩道計算" );
        CERR( "  \\Mathematics\\Geometry\\Graph\\Acyclic\\LongestWalk\\a.hpp" );
        CERR( "- 半順序集合の極大反鎖ならば、" );
        CERR( "  - 鎖への極小な分割のサイズを求めてDilworthの定理" );
        CERR( "    （あくまで個数のみの特定で、証明に基く帰納的構築は遅い）" );
        CERR( "    https://en.wikipedia.org/wiki/Dilworth%27s_theorem#Inductive_proof" );
          CERR( "  - トポロジカルソートされているならば、始切片としてNに埋め込み、" );
          CERR( "    半順序と整合的な後続関数S:N->Nを定義して、Sの値が元の集合に入らない" );
          CERR( "    要素全体の集合をSの単調性を用いて二分探索で計算" );
          CERR( "- 半開区間の極大排他的集合ならば、区間スケジューリング" );
          CERR( "  \\Mathematics\\Combinatorial\\IntervalScheduling\\a.hpp" );
          CERR( "- 同値関係の独立系の最大化（完全代表系の計算）ならば、深さ１の幅優先探索や" );
          CERR( "  による連結成分計算" );
          CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\QuotientSet" );
          CERR( "を検討しましょう。" );
          CERR( "" );
          CERR( "もしくはコストなしのナップサック問題を考えましょう。" );
      } else {
        CERR( "コストなしのナップサック問題を考えましょう。" );
      }
      CALL_AC( SingleKnapsackCostfree );
    }
  } else {
    CALL_AC( MinimisationPartitionOfSet );
  }
}

AC( MaximumBipartite )
{
  CERR( "二部グラフの最大二部マッチングは" );
  CERR( "- 出次数2ならば、連結成分ごとのmin(|V|,|E|)の総和" );
  CERR( "- そうでなく辺の出入りが等しい頂点を纏められるならば纏めた個数を容量とする" );
  CERR( "- 最大流計算アルゴリズム" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\MaximumFlow" );
  CERR( "- そうでないならばホップクロフトカープ法（または容量1の上記アルゴリズム)" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\HopcroftKarp" );
  CERR( "を検討しましょう。" );
}

AC( SubsetExhusiveSearch )
{
  CERR( "与えられた集合のサイズをNと置きます。" );
  CERR( "- O(2^N)が間に合いそうならば、bit全探策" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\BitExhausiveSearch" );
  CERR( "- O(N2^N)が間に合いそうならば、部分集合の包含対のbit全探策" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\BitExhausiveSearch" );
}

AC( MinimisationGraph )
{

  ASK_NUMBER(
             "コストの最小化問題" ,
             "価値の最大化問題"
             );
  if( num == num_temp++ ){
    CALL_AC( MinimisationGraphCost );
  } else {
    CALL_AC( MaximisationGraphValue );
  }
}

AC( MinimisationGraphCost )
{
  ASK_NUMBER(
	     "全域森のコスト最小化問題" ,
	     "パスのコスト最小化問題"
	     );
  if( num == num_temp++ ){
    CERR( "クラスカル法" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest\\Kruscal" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "これは最短経路問題そのものです。" );
    AC( MinimisationMovingCost );
  }
}

AC( MaximisationGraphValue )
{
  ASK_NUMBER(
	     "辺の価値最大化問題" ,
	     "頂点の価値最大化問題"
	     );
  if( num == num_temp++ ){
    CERR( "価値を-1倍したコストを考えることで辺のコスト最小化問題に帰着されます。" );
    CALL_AC( MinimisationGraphCost );
  } else {
    ASK_NUMBER(
               "非輪状グリッドグラフに埋め込み可能なグラフ" ,
               "その他のグラフ"
               );
    if( num == num_temp++ ){
      CERR( "非輪状グリッドグラフに埋め込み、平面走査と区間max更新" );
      CERR( "\\Mathematics\\Geometry\\Graph\\Grid\\ValueMaximisation" );
      CERR( "を検討しましょう。" );
    } else {
      CERR( "- 演算が加法ならば、始端の重み*(始点?2:1)と終端の重み*(終点?2:1)" );
      CERR( "  の和の-1倍を各辺の重みとして辺のコスト最小化問題に帰着" );
      CERR( "- 演算がmaxならば、始端の重みと終端の重みの最大値を" );
      CERR( "  各辺の-1倍の重みとして辺のコスト最小化問題に帰着" );
      CERR( "を検討しましょう。" );
      CALL_AC( MinimisationGraphCost );
    }
  }
}

AC( MaximisationOnTree )
{
  ASK_NUMBER(
	     "木上の関数の特定の部分集合上での最大／最小値計算問題" ,
	     "木の分割ごとに定まる値の最大／最小化問題" ,
	     "木のパスの長さの最大化問題" ,
	     "木の部分集合への最近傍探索問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryTree );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationPartitionOfTree );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationLengthOfPathOnTree );
  } else if( num == num_temp++ ){
    CALL_AC( NearestNeighbourOnTree );
  }
}

AC( MaximisationLengthOfPathOnTree )
{
  CERR( "- 重みなし木であれば、" );
  CERR( "  - 両端点が自由であれば直径" );
  CERR( "  - 片端点を固定するごとであれば、中心をc0,c1（同じでも可）" );
  CERR( "    としてc0を根としfloor(直径/2)をrと置いて" );
  CERR( "    (iの深さ)+(iがc0よりc1に近い?r:直径-r)" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Tree\\Diameter" );
  CERR( "- 重みつき木であれば、上位２位までを管理する木DP" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Tree\\Weighted\\Diameter" );
  CERR( "を検討しましょう。" );
}

AC( NearestNeighbourOnTree )
{
  CERR( "幅優先探索の要領で、集合をふくらませていきながら境界を管理しましょう。" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Tree\\NearestNeighbour" );
}

AC( MaximisationStringMatching )
{
  CERR( "基本的には丁寧にループを回して解きましょう。" );
  CERR( "- 比較対象が少ない場合、前または後ろから順に探索（貪欲法／動的計画法）" );
  CERR( "- ワイルドカードを含む場合、" );
  CERR( "  - 前または後ろから順に場合分けをしてO(N)で処理できるか" );
  CERR( "  - 可能な代入方法を絞り込んでO(N)種類に落せるか" );
  CERR( "- 比較回数が多い場合、ローリングハッシュ" );
  CERR( "  \\Utility\\String\\RollingHash" );
  CERR( "- 部分回文の最長化をする場合、尺取り法による前計算" );
  CERR( "  \\Utility\\String\\Palindrome" );
  CERR( "- マッチングする部分文字列の最長化をする場合、Zアルゴリズム" );
  CERR( "  \\Utility\\String\\Z-Algorithm" );
  CERR( "- マッチングする文字数の最大化をする場合、文字の種類分の{0,1}値配列に" );
  CERR( "  分けて内積の最大化（添え字を反転させて適当な法での畳み込み）" );
  CERR( "  \\Mathematics\\Arithmetic\\Mod" );
  CERR( "  \\Mathematics\\Polynomial" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationPartition )
{
  ASK_NUMBER(
             "配列Aの連続部分列への分割に関する最大／最小化問題" ,
             "集合の部分集合への分割に関する最大／最小化問題" ,
             "木の部分木への分割に関する最大／最小化問題"
             );
  if( num == num_temp++ ){
    CALL_AC( SortingArray );
    CERR( "" );
    CALL_AC( MinimisationPartitionOfArray );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationPartitionOfSet );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationPartitionOfTree );
  }
}

AC( MinimisationPartitionOfArray )
{
  CERR( "一般に始切片の分割Pに関する関数f(P)が与えられているとし、[0,N)の分割Pを" );
  CERR( "わたるf(P)の最大値（最小値は-fの最大値の-1倍）を考える際は、" );
  CERR( "dp[i] = 「[0,i)の分割Pをわたるf(P)の最大値」" );
  CERR( "を管理するiに関する動的計画法を検討しましょう。" );
  ASK_NUMBER(
             "Aの部分和の最大化問題" ,
             "f circ Aの部分和とg circ Aの補部分和の和の最大化問題" ,
             "Aの部分和と補部分和の差の最大／最小化問題" ,
             "Aの非空部分和と補集合の非空部分和の差の最小化問題" ,
             "Aの区間への分割全体をわたる区間和の絶対和の最大化問題"
             );
  if( num == num_temp++ ){
    CALL_AC( Knapsack );
  } else if( num == num_temp++ ){
    CERR( "f circ AをA_0、g circ AをA_1と置きます。" );
    CALL_AC( MaximisationFunctionOnTwoArray );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationSubsetSumDifferenceTwoPiece );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationSubsetSumDifferenceThreePiece );
  } else if( num == num_temp++ ){
    CALL_AC( KnapsackIntervalSumAbsoluteSum );
  }
}

AC( MinimisationPartitionOfSet )
{
  CERR( "- 半順序集合の鎖への極小な分割ならば、極大反鎖のサイズを求めて" );
  CERR( "  Dilworthの定理（あくまで個数のみの特定で、証明に基く帰納的構築は遅い）" );
  CERR( "  https://en.wikipedia.org/wiki/Dilworth%27s_theorem#Inductive_proof" );
  CERR( "- 同値関係の同値な要素からなる部分集合への分割の最小化（完全代表系の計算）" );
  CERR( "  ならば、深さ１の幅優先探索による連結成分計算" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\QuotientSet" );
}

AC( MaximisationPartitionOfTree )
{
  CERR( "木を受け取る関数fが与えられているとします。" );
  CERR( "" );
  CALL_AC( FunctionOnTree );
  CERR( "「第i頂点までで切った時のF(P)たちの最大値dp[i]」" );
  CERR( "を管理するiに関する動的計画法（O(N^2×fの計算量)）" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationProbability )
{
  CERR( "操作／戦略を選んで確率／期待値を最大化する場合、" );
  CERR( "被操作対象や可能な操作／戦略のデータなどを状態として定式化し、" );
  CERR( "「sを経由する場合の確率／期待値の最大値dp[s]」" );
  CERR( "を管理するsに関する動的計画法を検討しましょう。" );
}

AC( MinimisationOperationCost )
{
  CALL_AC( ReducingOperation );
  CERR( "損をしない変形方法がある時は、その変形で不変な操作方法のみに絞りましょう。" );
  CERR( "- 羃等操作ならば、各操作を高々一度だけ適用する。" );
  CERR( "- 可換操作ならば、各操作をソートして適用する。" );
  CERR( "- 羃等な区間作用ならば、排他的区間族のみ考慮する。" );
  CERR( "特に最適な操作の候補がある時は、その候補を特徴付ける関係式を求め、" );
  CERR( "任意の操作からコストを増加させずにその関係式を満たすように変形できるか" );
  CERR( "否かを確認しましょう。確認できればその候補のみ考えれば良く、" );
  CERR( "確認できなければその候補に執着せずに考察をしましょう。" );
  CERR( "" );
  ASK_NUMBER(
             "有向森の葉を削除して空にする問題" ,
             "数直線上の点群を移動させる問題" ,
             "順列をswapでソートする問題" ,
             "その他の問題"
             );
  if( num == num_temp++ ){
    CERR( "適宜根を追加して、根付き木を根のみに変形する問題に帰着させます。" );
    CERR( "親子関係にないノードの削除順を入れ替えられる必要十分条件を、" );
    CERR( "ノードの不変量の大小で記述しましょう。不変量が最大または最小なノードの" );
    CERR( "削除位置は後ろに自由に動かせるので、親子で連続削除される" );
    CERR( "と仮定して良いです。その親子を圧縮した場合の答えとのズレを管理して、" );
    CERR( "小さい根付き木に帰着させましょう。" );
  } else if( num == num_temp++ ){
    ASK_NUMBER(
               "点群を不定の区間に集める問題" ,
               "点群を特定の部分集合に集める問題"
               );
    if( num == num_temp++ ){
      CERR( "[l,r]を取り、lより左の点は右へ、rより右の点は左へのみ移動させる" );
      CERR( "問題を考えます。" );
      CERR( "- (-∞,l)内の点群集合S_lと(r,∞)内の点群集合T_rからコストを算出し、" );
      CERR( "  lを決め打った時のrの最適値をlで表示" );
      CERR( "- lからrが一意に決まったら、lを決め打った時のコストC(l)を求め、" );
      CERR( "  C(l)（またはS_lやT_r）の差分計算" );
      CERR( "- C(l)が下に凸（差分が単調増加）であれば三分探索や差分の二分探索" );
      CERR( "を検討しましょう。" );
    } else if( num == num_temp++ ){
      CERR( "最近点問題に帰着させましょう。" );
      CALL_AC( NearestNeighbour );
    }
  } else if( num == num_temp++ ){
    CERR( "順列をswapでソートするのに必要な回数は" );
    CERR( "(グラフの辺数) = (長さ)-(グラフの連結成分数)です。" );
    CERR( "グラフの辺数の遷移を考えると、この回数が達成可能なのは" );
    CERR( "グラフ上で隣接する2項をswapしていく場合のみだと分かります。" );
  } else if( num == num_temp++ ){
    ASK_YES_NO( "操作回数の上限は10^6以下ですか？" );
    if( reply == "y" ){
      CERR( "操作回数ごとに最適状態を管理する動的計画法を検討しましょう。" );
      CERR( "特に最適な操作が何らかの値を倍にする場合、その値の上限の" );
      CERR( "log_2で操作回数を抑えられることに注意しましょう。" );
    }
    ASK_YES_NO( "操作コストが1（操作回数の最小化問題）ですか？" );
    if( reply == "y" ){
      CERR( "操作回数を決め打って目的の達成が判定できるならば、二分探索を" );
      CERR( "検討しましょう。" );
    } else {
      ASK_YES_NO( "各操作が可換ですか？" );
      if( reply == "y" ){
        CERR( "コスト正の各操作を実行する回数を決定すれば良いので、" );
        CERR( "- コスト0の操作のみで処理できる必要十分条件の決定" );
        CERR( "- コスト正の操作回数の合計kを決め打った時の最小コストc(k)の決定" );
        CERR( "  - c(k)が単調ならばc(k)の最小値を二分探索" );
        CERR( "  - c(k)が凸ならばc(k)の最小値を三分探索" );
        CERR( "  - 一般にはc(k)の最小値を全探策" );
        CERR( "- コスト正の操作回数の組み合わせの全探策" );
        CERR( "を検討しましょう。" );
      }
    }
    ASK_YES_NO( "状態は10^6個以下ですか？" );
    if( reply == "y" ){
      CERR( "操作コストの最小化は、操作による状態遷移を有向グラフ上の移動とみなすことで" );
      CERR( "最短経路問題に帰着させることが可能です。" );
      CALL_AC( MinimisationMovingCost );
    }
  }
}

AC( MaximisationCountingOperation )
{
  CALL_AC( ReducingOperation );
  ASK_YES_NO( "その上で状態が10^6オーダーですか？" );
  if( reply == "y" ){
    CERR( "状態の遷移をグラフ上の移動とみなし、最長経路問題に帰着させましょう。" );
    CALL_AC( MaximisationMovingDistance );
  } else {
    CERR( "操作回数の見積りには" );
    CERR( "- 操作回数sを決め打った時の操作可能性b(s)に関する二分探索" );
    CERR( "- 操作の種類が複数あるならば、片方の回数sを決め打った時の" );
    CERR( "  もう片方の回数の最大値t(s)を求め、s+t(s)の最大化" );
    CERR( "- 操作対象が複数あるならば" );
    CERR( "  - 操作優先度があるならば、対象を優先度順に並び変えた上で" );
    CERR( "    dp[i] =「i番目の対象の操作回数最大値」" );
    CERR( "    を管理するiに関する動的計画法" );
    CERR( "  - 各対象への操作が独立に行えるならば、" );
    CERR( "    dp[i] =「i番目までの対象のみに操作する時の操作回数最大値」" );
    CERR( "    を管理するiに関する動的計画法" );
    CERR( "  - 操作順に意味がなく各対象に高々１回しか操作しないならば、" );
    CERR( "    操作する対象全体のなす部分集合の全探策や半分全列挙" );
    CERR( "操作方法の探索には" );
    CERR( "- 操作によって不変量が減る量が最小になるような操作の反復" );
    CERR( "- ほとんど同じ操作の反復" );
    CERR( "を検討しましょう。" );
  }
}

AC( MinimisationCoveringSize )
{
  CERR( "頂点数をV、辺の本数をE、被覆枚数をKと置きます。" );
  ASK_NUMBER(
             "K個の被覆中心からの距離の最小値Lの最小化問題" ,
             "長さL以下の辺を残す部分グラフの連結成分がK個以下となるLの最大化問題"
             );
  if( num == num_temp++ ){
    CERR( "Lを決め打って被覆可能性を判定する二分探索を検討しましょう。" );
    ASK_YES_NO( "Eが10^{-6}以下ですか？" );
    if( reply == "y" ){
      CALL_AC( MinimisationCoveringSizeSmallEdge );
    }
    ASK_YES_NO( "被覆中心（始点）は固定ですか？" );
    if( reply == "y" ){
      CERR( "被覆可能性を描画図形の一致判定に翻訳しましょう。" );
      CERR( "" );
      CALL_AC( DecisionImageCoincidence );
    } else {
      CERR( "始点（被覆中心または被覆端点）の候補を絞った上で" );
      CERR( "始点を１つ決め打ってその始点から距離L以内の点を削除し、" );
      CERR( "残りの点群に対して再帰的に問題を解くことを検討しましょう。" );
      CERR( "特にユークリッド空間では" );
      CERR( "- l^1距離ならば45度回転させl^∞距離に帰着" );
      CERR( "- K=1ならば、[min,max]の端点いずれかを被覆端点として全点との距離計算" );
      CERR( "- K>1ならば、各成分の[min,max]に注目して頂点を含む最小直方体の角を" );
      CERR( "  １つの被覆端点に決め打って全探策し、K-1の場合に帰着" );
      CERR( "を検討しましょう。" );
      CERR( "" );
      CERR( "もしくは被覆可能性を描画可能性に翻訳します。" );
      CALL_AC( DecisionDrawability );
    }
  } else {
    CERR( "- O((V+E)log(Lの上限))が間に合いそうならば、L決め打ち二分探索で" );
    CERR( "  幅優先探索" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorith\\BreadthFirstSearch" );
    CERR( "- O(E(log E+α(V)))が間に合いそうならば、重みで辺をソートして" );
    CERR( "  素集合データ構造" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  }
}

AC( MinimisationCoveringSizeSmallEdge )
{
  CERR( "- コストがなくO(V+E)が通りそうならば、多点幅優先探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "- コストが0か1でO(V+E)が通りそうならば、多点01幅優先探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\ZeroOne" );
  CERR( "- max演算を考えておりO(E(log_2 E + α(V)))が通りそうならば、" );
  CERR( "  重みで辺をソートして素集合データ構造" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "- O((V+E)log_2 E)が通りそうならば、" );
  CERR( "  頂点を１つ追加し各始点に辺を張ったグラフ上でのダイクストラ法" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
  CERR( "- O(V^3)が通りそうならば、" );
  CERR( "  ワーシャルフロイド法" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\FloydWarshall" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationDrawingImage )
{
  CERR( "描画個数の最大／最小化は描画サイズの最小／最大化に帰着させましょう。" );
  CERR( "描画サイズの最大／最小化問題はサイズを決め打った二分探索や各点でのサイズの最大化" );
  CERR( "などを行い描画可能性判定に帰着させましょう。" );
  CERR( "" );
  CALL_AC( DecisionDrawability );
}

AC( MinimisationSolution )
{
  CERR( "条件P(x)を満たすxを考えます。" );
  CERR( "- xの属す集合Sが小さいならば、Sの要素を全探策" );
  CERR( "- P(x)が方程式f(x)=0で与えられるならば、" );
  CERR( "  - fの増減の変化点が少ないならば、単調区間を左から順に調べ端点での値を計算し、" );
  CERR( "    0を跨ぐ時のみその区間内で二分探索" );
  CERR( "  - fの区間ごとに解の有無が計算できるならば、区間縮小法" );
  CERR( "- マルチテストケースでcが与えられP(x)が方程式f(x)=g(c)で与えられるならば、" );
  CERR( "  - xを全探策してf(x)を前計算し、連想配列でyごとに" );
  CERR( "    y=f(x)を満たすxの最大／最小値を管理" );
  CERR( "- P(x)が方程式∃k[f(x)=g(k)]で与えられkの候補が少ないならば、" );
  CERR( "  kごとにxの最大／最小値を計算" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationMinimum )
{
  CERR( "最小値の最大化は-1倍により最大値の最小化に帰着させます。" );
  ASK_NUMBER(
             "配列に成分ごとの操作を行った際の最大値の最小化" ,
             "集合上の関数の部分集合における最大値の最小化" ,
             "操作群の操作コストの最大値の最小化"
             );
  if( num == num_temp++ ){
    CERR( "最大値の上界を固定して操作の可否を判定する二分探索により" );
    CERR( "真偽判定問題に帰着させましょう。" );
    CALL_AC( Decision );
  } else if( num == num_temp++ ){
    CERR( "最大値を演算とみなすことで、部分和の最小化問題とみなせます。" );
    CALL_AC( MinimisationSubsetSum );
  } else if( num == num_temp++ ){
    CERR( "羃等重みに関する最短経路問題に帰着させましょう。" );
    CALL_AC( MinimisationMovingCost );
  }
}

AC( MinimisationSubsetSum )
{
  ASK_NUMBER(
	     "グラフの辺集合E上の関数の部分和の最小化問題" ,
	     "一般の集合上の関数の部分和の最小化問題"
	     );
  if( num == num_temp++ ){
    CERR( "最短経路問題に帰着させましょう。" );
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CERR( "部分和を固定して部分集合の存在を判定する二分探索により" );
    CERR( "真偽判定問題に帰着させましょう。" );
    CALL_AC( Decision );
  }
}

AC( MinimisationSubsetSumDifference )
{
  ASK_NUMBER(
             "Aの部分和と補部分和の差の最大／最小化問題" ,
             "Aの非空部分和と補集合の非空部分和の差の最小化問題"
             );
  if( num == num_temp++ ){
    CALL_AC( MinimisationSubsetSumDifferenceTwoPiece );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationSubsetSumDifferenceThreePiece );
  }
}

AC( MinimisationSubsetSumDifferenceTwoPiece )
{
  CERR( "「Aの補部分和」は定数「Aの総和」から「Aの部分和」を引いたものです。" );
  CERR( "差が引き算の絶対値であることから、絶対値を取る前の値である" );
  CERR( "2×「Aの部分和」-「Aの総和」" );
  CERR( "に注目します。" );
  ASK_NUMBER(
             "Aの部分和と補部分和の差の最小化問題" ,
             "Aの部分和と補部分和の差の最大化問題" ,
             );
  if( num == num_temp++ ){
    CERR( "差の最小化は「Aの部分和」と「Aの総和の半分」の差の最小化に帰着しましょう。" );
    CERR( "２つの値のうち小さい方を考えることで上限付き部分和の最大化問題となります。" );
  } else if( num == num_temp++ ){
    CERR( "差の最大化は「Aの部分和」が最大か最小である場合に達成されます。" );
    CERR( "Aと-Aを考えることで、部分和の最大化問題となります。" );
  }
  CERR( "" );
  CALL_AC( Knapsack );
}

AC( MinimisationSubsetSumDifferenceThreePiece )
{
  CERR( "非空部分集合とその補集合の非空部分集合をそれぞれS,Tと置き、" );
  CERR( "定数Cによる|#S - #T|<=Cという制約以外には制約がないとします。" );
  CERR( "" );
  CERR( "定義からSとTは交わりが空ですが、部分和の差を考える上では交わりを" );
  CERR( "持たせても答えは変わらないため、結局|#S - #T| <= Cを守りつつ" );
  CERR( "要素数が[floor(N/2),floor(N/2)+C]に属す相異なる非空部分集合" );
  CERR( "の組全体に(S,T)を渡らせてAの部分和の差の最小化を" );
  CERR( "する問題に帰着されます" );
  CERR( "" );
  CERR( "和を取る値の幅をv_maxと置き、集合の要素数をNと置くと、" );
  CERR( "部分和の候補は高々v_max N通り、要素数floor(N/2)の部分集合の候補は" );
  CERR( "約2^N/√N通りで、log_2(v_max N)の定数倍 < Nならば鳩の巣原理より" );
  CERR( "答えは0です。" );
  CERR( "" );
  CERR( "以下N <= log_2(v_max N)の定数倍とします。" );
  CERR( "排他的なS,Tを半分列挙することで答えをO(CN 3^{N/2})で求められ、" );
  CERR( "結局O(N + C v_max^{(log_2 3)/2} log_2 v_max)で解く" );
  CERR( "ことが可能です。" );
  CERR( "  \\Mathematics\\Combinatorial\\Knapsack\\Costfree\\Difference" );
}

AC( MaximisationGame )
{
  ASK_YES_NO( "整礎なゲームですか？" );
  if( reply == "y" ){
    ASK_NUMBER(
               "双方の総得点の差の最大化と最小化を目指すゲーム" ,
               "双方の距離の最大値の最大化と最小化を目指すゲーム" ,
               "１つの数列を交互に操作して最終的な要素の最大化と最小化を目指すゲーム"
               );
    if( num == num_temp++ ){
      CALL_AC( MaximisationGameWellFoundedTotalDifference );
    } else if( num == num_temp++ ){
      CALL_AC( MaximisationGameWellFoundedEachDifference );
    } else {
      CALL_AC( MaximisationGameWellFoundedArrayOperation );
    }
  } else {
    CALL_AC( MaximisationGameIllFounded );
  }
}

AC( MaximisationGameWellFoundedTotalDifference )
{
  CERR( "数列や多重集合から成分や要素である項を交互に削除していき、項iを" );
  CERR( "先行が削除した場合は先行にA[i]点、後行が削除した場合は後行にB[i]点" );
  CERR( "が与えられるとし、先行の総得点をX、後行の総得点をYと置きます。" );
  CERR( "- 先行がX-Yの最大化を、後行がX-Yの最小化を目指す問題ならば、" );
  CERR( "  双方がA[i]+B[i]の大きい順に貪欲に選ぶ場合が双方の最善です。" );
  CERR( "- 先行がX-Yの最小化を、後行がX-Yの最大化を目指す問題ならば、" );
  CERR( "  双方がA[i]+B[i]の小さい順に貪欲に選ぶ場合が双方の最善です。" );
  CERR( "- 先行がX+Yの最大化を、後行がX+Yの最小化を目指す問題ならば、" );
  CERR( "  双方がA[i]-B[i]の大きい順に貪欲に選ぶ場合が双方の最善です。" );
  CERR( "- 先行がX+Yの最小化を、後行がX+Yの最大化を目指す問題ならば、" );
  CERR( "  双方がA[i]-B[i]の小さい順に貪欲に選ぶ場合が双方の最善です。" );
  CERR( "これに従って配列の和／差をソートして実際に操作を実行しましょう。" );
}

AC( MaximisationGameWellFoundedEachDifference )
{
  CERR( "数列や多重集合から成分や要素である項を交互に削除していき、項iを" );
  CERR( "削除したプレイヤーは位置A[i]に移動するとします。" );
  CERR( "2プレイヤー間距離の最大値は、最大化を目指す側が最善を目指す限り" );
  CERR( "最小化を目指すプレイヤーの選択によらず(max A)-(min A)です。" );
}

AC( MaximisationGameWellFoundedArrayOperation )
{
  CERR( "数列の成分を先手が選び、演算を後手が選び、それらを適用して得点を" );
  CERR( "操作するゲームを考えます。" );
  CERR( "数列を昇順にソートし、演算を強い順にソートし、それらを順に適用した" );
  CERR( "結果Xを考えます。" );
  CERR( "- 先手が確実に達成できる値の最大値は何か" );
  CERR( "- 後手が確実に達成できる値の最小値は何か" );
  CERR( "をXをヒントに算出しましょう。" );
}

AC( MaximisationGameIllFounded )
{
  CERR( "局面を反復可能なゲームは反復戦略を取ることで初期局面に帰着されます。" );
  CERR( "- 先行が最終着手を行う場合、初手での最大化問題に帰着し" );
  CERR( "  初手のうち無駄がないものを全探策" );
  CERR( "- 後行が最終着手を行う場合、２手目での最小値の最大化問題に帰着し" );
  CERR( "  初手のうち無駄がないものを固定するごとに２手目の最小値を計算" );
  CERR( "- 最終的な不変量の下界を決め打った時にそれ以上の不変量を得ることが" );
  CERR( "  実現可能な必要十分条件が決定できる場合、それによる最大値の計算" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "数値を置き換えるゲームは頻度表を用いて数値を移動するゲームに" );
  CERR( "翻訳できることがありますが、その場合は数値の移動が結果的に" );
  CERR( "起こらない操作も許されるか否かに注意しましょう。" );
}

AC( MinimisationExpression )
{
  CERR( "項tを集合Sの要素とモノイド演算*、群演算+、写像fを用いて" );
  CERR( "t=f(*総乗)+(*総乗)" );
  CERR( "と表示する時の表示長の最小化問題は*総乗をkeyとして総乗長の最小値を" );
  CERR( "管理する連想配列を用いることで解くことができます。" );
  CERR( "\\Mathematics\\Combinatorial\\AlgebraicGeneration" );
  CERR( "" );
  CERR( "特に*による総乗長の最小化は+=*、f=idとすることで半分全列挙で" );
  CERR( "求めることができます。" );
}

AC( Counting )
{
  ASK_YES_NO( "複数の条件を満たす項の数え上げ問題ですか？" );
  if( reply == "y" ){
    CERR( "条件P_1,...,P_rの真偽が固定されている場合、" );
    CERR( "条件をいくつか除いたり逆にしたりした場合を計算し、包除原理などで" );
    CERR( "答えを求めましょう。" );
    CERR( "例えば全事象Uの排他的被覆を与える事象A,B,C,Dがある時、" );
    CERR( "#A = #(A cup B) + #(A cup C) + #(A cup D) - #U" );
    CERR( "などと計算することができます。" );
  }
  ASK_YES_NO( "クエリ問題ですか？" );
  if( reply == "y" ){
    CALL_AC( QueryCounting );
  } else {
    ASK_NUMBER(
               "数（配列の添字）の数え上げ問題" ,
               "組（行列の添字）の数え上げ問題" ,
               "配列の数え上げ問題" ,
               "順列の数え上げ問題" ,
               "文字列の数え上げ問題" ,
               "行列の数え上げ問題" ,
               "グラフの数え上げ問題" ,
               "グラフの彩色の数え上げ問題" ,
               "部分集合の数え上げ問題" ,
               "分割の数え上げ問題" ,
               "写像の数え上げ問題" ,
               "戦略／操作方法の数え上げ問題" ,
               "経路の数え上げ問題" ,
               "タイリング／塗り分けの数え上げ問題" ,
               "ヤング図形の数え上げ問題" ,
               "操作回数の計算問題"
               );
    if( num == num_temp++ ){
      CALL_AC( CountingNumber );
    } else if( num == num_temp++ ){
      CALL_AC( CountingPair );
    } else if( num == num_temp++ ){
      CALL_AC( CountingArray );
    } else if( num == num_temp++ ){
      CALL_AC( CountingPermutation );
    } else if( num == num_temp++ ){
      CALL_AC( CountingString );
    } else if( num == num_temp++ ){
      CALL_AC( CountingMatrix );
    } else if( num == num_temp++ ){
      CALL_AC( CountingGraph );
    } else if( num == num_temp++ ){
      CALL_AC( CountingGraphColouring );
    } else if( num == num_temp++ ){
      CALL_AC( CountingSubset );
    } else if( num == num_temp++ ){
      CALL_AC( CountingPartition );
    } else if( num == num_temp++ ){
      CALL_AC( CountingMap );
    } else if( num == num_temp++ ){
      CALL_AC( CountingStrategy );
    } else if( num == num_temp++ ){
      CALL_AC( CountingPath );
    } else if( num == num_temp++ ){
      CALL_AC( CountingTiling );
    } else if( num == num_temp++ ){
      CALL_AC( CountingYoundDiagram );
    } else if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionCountingOperation );
    }
    ASK_YES_NO( "答えが明示式で表せましたか？" );
    if( reply == "y" ){
      CALL_AC( ExplicitExpression );
    }
    ASK_YES_NO( "サンプルを解析しますか？" );
    if( reply == "y" ){
      CALL_AC( SampleAnalyser );
    }
  }
  ASK_YES_NO( "計算量が2乗に大きい程度の動的計画法で解けますか？" );
  if( reply == "y" ){
    CERR( "- dp[i]の代わりに" );
    CERR( "  - sum_{k<=i}dp[k]を考える。" );
    CERR( "  - i番目の状態をdp[i+1]への寄与C(k)が等しい状態kへ細分してdp[i][k]を考える。" );
    CERR( "  - i番目の状態をdp[i+1]への寄与がcである状態の和集合へ細分してdp[i][c]を考える。" );
    CERR( "- dp[i][i] = *_i(dp[i][0,i))かつdp[i][j]=dp[j][j] o dp[i-1][j]を" );
    CERR( "  満たすモノイド演算*と作用oが存在するならば、dp[i][i]を別個に管理して" );
    CERR( "  NextDPの遷移を区間加算や区間作用が可能なデータ構造でinplace化。" );
    CERR( "- 状態数が多い場合、状態の満たす関係式を特定して状態数の削減。" );
    CERR( "を検討しましょう。" );
  }
}

AC( CountingNumber )
{
  CERR( "何らかの条件を満たす数の数え上げ問題を考えます。" );
  ASK_NUMBER(
	     "各桁の数字に関する条件" ,
	     "それ以外の固定長変数関数の値に関する条件" ,
	     "その他の条件"
             );
  if( num == num_temp++ ){
    CERR( "数を十進法などで文字列とみなします。" );
    CALL_AC( CountingArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingExplicitExpression );
  } else {
    CERR( "条件P(n)を満たすN以下の非負整数nの数え上げは、関数f(n) = P(n)?1:0などの" );
    CERR( "総和の計算問題に帰着されます。" );
    CALL_AC( ExplicitExpressionOneArrayEntrySum );
  }
}

AC( CountingPair )
{
  CERR( "条件P(i,j)を満たすN未満の非負整数iとM未満の非負整数jの数え上げは、" );
  CERR( "関数f(i,j) = P(i,j)?1:0などの総和の計算問題に帰着されます。" );
  CALL_AC( ExplicitExpressionDoubleSum );
}

AC( CountingExplicitExpression )
{
  CERR( "- 変数の対称性があれば大小関係を制限した全探策" );
  CERR( "- 何らかの約数となるなど動く範囲が狭い変数があればそれらを決め打った全探策" );
  CERR( "- 半順序集合への特定の写像の逆像ならばゼータ変換／メビウス変換" );
  CERR( "  \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "- gcd(n,x)=1かつ1<=x<=nを満たすxの数え上げはオイラー関数" );
  CERR( "  \\Mathematics\\Arithmetic\\Mod\\Function\\Euler" );
  CERR( "- f(g(x),g(y))=cの形ならば以下の分割統治法：" );
  CERR( "  - まず各b in im(g)に対しf(a,b) = cを満たすa in im(g)全体を前計算する。" );
  CERR( "  - 次に|dom(g)| = N、max im(g) = Mとして、各y in im(g)に対する" );
  CERR( "    逆像の濃度|g^{-1}(y)|を管理するg_inv[y]を" );
  CERR( "    - O(N)が間に合いそうならばunordered_map::g_inv[g[x]]++" );
  CERR( "    - O(M+N)が間に合いそうならば配列::g_inv[g[x]]++" );
  CERR( "    - x,yに制限h(x)<h(y)がある場合はh(x)の上限cについてループして" );
  CERR( "      g_inv[g(x)]++していき、それと並行してyをc<h(y)の範囲で全探索" );
  CERR( "    により管理する。" );
  CERR( "  - 最後に各yごとにf(a,g(y)) = cを満たす各a in im(g)に対しa = g(x)を満たす" );
  CERR( "    xをg_inv[a]で数え上げる" );
  CERR( "- f(g(x),g(y))<=cの形かつfとgが単調増加するならば以下の分割統治法：" );
  CERR( "  - まず各b in im(g)に対しf(a,b) <= cを満たすaの上限を二分探索で前計算する。" );
  CERR( "  - 次にそうして得られる各aに対しg(x)<=aを満たすxの上限を二分探索で前計算する。" );
  CERR( "  - 最後に各yごとにb = g(y)に対する前計算結果の総和を求める。" );
  CERR( "- 平方数の和ならばヤコビの二平方定理" );
  CERR( "  https://ja.wikipedia.org/wiki/ヤコビの二平方定理" );
  CERR( "を検討しましょう。" );
}

AC( CountingArray )
{
  ASK_NUMBER(
             "条件を満たす配列の数え上げ問題" ,
             "与えられた配列の部分列の数え上げ問題" ,
             "与えられた配列の添字の数え上げ問題"
             );
  if( num == num_temp++ ){
    CALL_AC( CountingArrayConditional );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingNumber );
  }
}

AC( CountingArrayConditional )
{
  ASK_NUMBER(
	     "配列を受け取る関数の値が固定された配列の数え上げ問題" ,
	     "隣接成分間関係式を満たす配列の数え上げ問題" ,
	     "辞書式順序などで固定長の部分列に上限が与えられた配列の数え上げ問題" ,
             "閉じたカッコ列やその亜種の数え上げ問題" ,
	     "その他の関係式を満たす配列の数え上げ問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingArrayInverseImage );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArrayAdjacentRelation );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArrayBounded );
  } else if( num == num_temp++ ){
    CALL_AC( CountingParenthesisSequence );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArrayOtherRelation );
  }
}

AC( CountingArrayInverseImage )
{
  CERR( "配列の長さをN、成分の取りえる値の個数をB、配列を受け取る関数をf、" );
  CERR( "fの取る値のうち考慮すべき個数をVとします。" );
  ASK_NUMBER(
             "fが配列との整数値内積である問題" ,
             "fが配列との法B値内積である問題" ,
             "fが2項演算の反復である問題" ,
             "fがその他のNに関して再帰的構造を持つ問題" ,
             "fが上記のいずれでもない問題"
             );
  CERR( "- O(B^N)が間に合いそうならば、全ての配列に対するfの値の前計算" );
  if( num == 0 ){
    CERR( "- O(N^2 log N)が間に合いそうでかつ配列が有界整数列でfが" );
    CERR( "  非零整数係数ベクトルCによる内積であるならば、" );
    CERR( "  「長さiの時に値vである配列の総数dp[i][v]」" );
    CERR( "  が漸化式dp[i+1][v] = sum_{j<=v/C[i+1]} dp[i][v-j*C[i+1]]を" );
    CERR( "  満たすことからf_i(x,v)=dp[i][v-x*C[i+1]]と置いてその累積和" );
    CERR( "  sum_{j<=x} f_i(j,v)" );
    CERR( "  をS(f_i,v)(x)と置いて得られる漸化式" );
    CERR( "  f_1(x,v) = (v%C[2]==0?1:0)" );
    CERR( "  f_{i+1}(x,v) = S(f_i,v)((v-x*C[i+2])/C[i+1])" );
    CERR( "  を累積和のアフィン変換で処理してdp[i][v]=f_i(0,v)を計算" );
    CERR( "  \\Mathematics\\Polynomial\\CumulativeSum" );
    CERR( "  \\Mathematics\\Polynomial\\ParallelTranslation" );
  } else if( num == 1 ){
    CERR( "- O(log N)が成り立ちそうでかつ配列が法B整数列でfが法B等比数列C" );
    CERR( "  による法B内積であるならば、" );
    CERR( "  - Cの初項が可逆ならば初項のみに自由度があるので答えは(B-1)^{N-1}" );
    CERR( "  - 配列の各成分に非零の禁止条件があるならば、Cはlog_2 B成分以降" );
    CERR( "    定数の可逆元倍であることに注意して" );
    CERR( "    「第i-1成分まで0、第i+1成分以降非零に緩めた時の総数dp0[i]」" );
    CERR( "    「第i-1成分まで0、第i成分以降非零に緩めた時の総数dp1[i]」" );
    CERR( "    をi=[log_2 B]から大きい順に求めてdp1[0]を計算" );
  } else if( num == 2 ){
    CERR( "- O(NV^V)が間に合いそうならば、" );
    CERR( "  「長さiの時にfのi+1重片側合成が関数gである配列の総数dp[i][g]」" );
    CERR( "  を管理するi,vに関する動的計画法" );
  }
  if( num <= 3 ){
    CERR( "- O(NV)が間に合いそうならば、" );
    CERR( "  「長さiの時に値vである配列の総数dp[i][v]」" );
    CERR( "  を管理するi,vに関する動的計画法" );
    CERR( "  - 特に非負整数値関数gを用いてf(A)=sum_i g(A[i])と表せるならば、" );
    CERR( "    gの頻度表を前計算して頻度で重み付けてdp更新" );
    CERR( "  - 特に非負有理数値関数gを用いてf(A)=sum_i g(A[i])と表せるならば、" );
    CERR( "    gの値の分母が大きな素数になる成分だけ別個に考えてgの値の分母の" );
    CERR( "    最小公倍数が小さい場合に帰着させ、通分して整数値の場合に帰着" );
  }
  CERR( "- 関数が区間和などデータ構造で計算できる値で表せるならば、" );
  CERR( "  データ構造に翻訳した上での数え上げ" );
  CERR( "を検討しましょう。" );
}

AC( CountingArrayAdjacentRelation )
{
  CERR( "- 半順序での単調性の場合、" );
  CERR( "  - 全順序ならば、数の分割方法などへの翻訳" );
  CERR( "  - 疎な半順序ならば、グラフの前計算" );
  CERR( "- その他の条件の場合は動的計画法で、" );
  CERR( "  - 禁止条件の時は余事象を引く更新" );
  CERR( "  - 複数条件の時は包除原理による更新" );
  CERR( "  - 特定の部分列（例えばaba）を含むという条件の時は" );
  CERR( "    (1) 長さiかつabaを含まないかつ末尾がaなものの個数dpa[i]" );
  CERR( "    (2) 長さiかつabaを含まないかつ末尾がabなものの個数dpab[i]" );
  CERR( "    (3) 長さiかつabaを含むものの個数dpaba[i]" );
  CERR( "    を再帰式" );
  CERR( "    (1) dpa[i] = (26^{i-1}-dpaba[i-1]-dpab[i-1])*1" );
  CERR( "    (2) dpab[i] = (26^{i-2}-dpaba[i-2]*26 + dpab[i-2])*1" );
  CERR( "    (3) dpaba[i] = dpaba[i-1]*26 + dpab[i-1]*1" );
  CERR( "    を用いてiに関する動的計画法で計算" );
  CERR( "を検討しましょう。" );
}

AC( CountingArrayBounded )
{
  CERR( "上限をsと置き、sの長さをL、数え上げる配列の長さをNと置き、" );
  CERR( "数え上げる配列の属す集合をSと置きます。" );
  ASK_YES_NO( "L == Nですか？" );
  if( reply == "y" ){
    ASK_NUMBER(
               "１つのsに対する数え上げ" ,
               "s全体に対する数え上げの総和"
               );
    if( num == num_temp++ ){
      CALL_AC( CountingArrayBoundedTotal );
    } else {
      CALL_AC( CountingArrayMultipleBoundedTotal );
    }
  } else {
    CALL_AC( CountingArrayBoundedSub );
  }
}

AC( CountingArrayBoundedTotal )
{
  CERR( "文字列集合S内でs未満の項の数え上げをする際は、" );
  CERR( "長さや文字種類数などの状態を考えて" );
  CERR( "dp[d][n] = 「Sと先頭d文字目で初めてズレる状態nの項の総数」" );
  CERR( "をdとnに関する動的計画法で求めましょう。" );
}

AC( CountingArrayMultipleBoundedTotal )
{
  CERR( "配列を非負整数に翻訳すると、総和を取る順番は関係ないのでsを対応する数に" );
  CERR( "関して昇順に並べてs_0:=0<=s_1<s_2<...としてよく、その場合の数え上げを" );
  CERR( "sの区間に分割する分割統治法" );
  CERR( "sum_i #(S cap [s_{i-1},s_i)) * i" );
  CERR( "を検討しましょう。特にSが区間でs_i = iならばsum_i iです。" );
}

AC( CountingArrayBoundedSub )
{
  CERR( "長さLの全ての部分文字列がs未満であるという条件を、Sの定義を用いて" );
  CERR( "簡単な条件に翻訳しましょう。" );
  CERR( "そのためにはLが小さい具体的なsに対して実験し、法則や上限を見付けましょう。" );
  CERR( "この際に辞書式順序と積順序を混同しないように注意しましょう。" );
}

AC( CountingArrayOtherRelation )
{
  ASK_YES_NO( "順列の数え上げですか？" );
  if( reply == "y" ){
    CALL_AC( CountingPermutation );
  } else {  
    ASK_YES_NO( "配列への格納順が関係ありますか？" );
    if( reply == "y" ){
      ASK_YES_NO( "総和が0で左端からの始端和が非負な±1列ですか？" );
      if( reply == "y" ){
        CERR( "長さ2Nの閉じたカッコ列に対応します。" );
        CALL_AC( CountingParenthesisSequence );
      } else {
        CERR( "添字に半順序を構成しグラフの数え上げに帰着することを検討しましょう。" );
        CALL_AC( CountingGraph );
      }
    } else {
      CERR( "（多重）集合やソートされた配列の数え上げに帰着することを検討しましょう。" );
      CALL_AC( CountingSubset );
    }
  }
}

AC( CountingSubArray )
{
  ASK_NUMBER(
	     "配列の成分を受け取る関数の部分和を固定した部分列の数え上げ問題" ,
	     "配列の隣接成分間関係式を満たす部分列の数え上げ問題" ,
	     "配列のその他の関係式を満たす部分列の数え上げ問題" ,
	     "配列の部分列から取得位置情報を落とした配列の数え上げ問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingSumFixedSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrictedSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingGeneralRelationSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubArrayImageArray );
  }
}

AC( CountingSumFixedSubArray )
{
  CERR( "和を取る値を価値と呼ぶことにします。" );
  CERR( "配列の項数N、第i成分の価値A_i、価値の総和v、vの上限Vとします。" );
  CERR( "{0,...,N-1}の部分集合Iであって、" );
  CERR( "- sum(i in I){A_i} = v" );
  CERR( "- その他の条件" );
  CERR( "を満たすものの数え上げを考えます。" );
  ASK_NUMBER(
	     "Iにコスト制約がある場合" ,
	     "Iが連続部分列に限られる場合" ,
	     "Iに追加の制約がない場合"
	     );
  if( num == num_temp++ ){
    CERR( "O(2^N)が通りそうならば価値とコストを次数とする愚直な２変数多項式乗算" );
    CERR( "  \\Mathematics\\Polynomial\\Multivariable" );
  } else if( num == num_temp++ ){
    CERR( "- O(N^2)が通りそうならば累積和で差の取得" );
    CERR( "- O(N log_2 N)が通りそうでv=0に固定ならば累積和でCountUnitProdRange" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\CumulativeProd" );
  } else if( num == num_temp++ ){
    CERR( "- O(2^N)が通りそうならば愚直な１変数多項式乗算" );
    CERR( "- O(2^{N/2}N)が通りそうでvが１つの値に固定ならば半分ずつ多項式乗算をして" );
    CERR( "  最後にそれらの積のv次係数のみの計算" );
    CERR( "- O((N+V)log_2 V)が通りそうでVが10^5オーダーで" );
    CERR( "  プロス素数Pを法とするならば法Pでの高速フーリエ変換による" );
    CERR( "  exp(logの総和)計算" );
    CERR( "  \\Mathematics\\Polynomial\\Truncate" );
    CERR( "  https://yukicoder.me/submissions/1115449" );
  }
  CERR( "を検討しましょう。" );
}

AC( CountingRestrictedSubArray )
{
  ASK_NUMBER(
	     "連続部分列の数え上げ問題" ,
	     "連続とは限らない部分列の数え上げ問題" ,
	     "部分順列（部分列の並び換え）の数え上げ問題"
	     );
  CERR( "長さNの配列Aと、L+n<=N+1を満たす整数n,Lと" );
  CERR( "- 整数iに関する条件Q(i)" );
  CERR( "- 各0<=l<Lに対するn-tuple(b_0,...,b_{n-1})に関する条件R_l(b_0,...,b_{n-1})" );
  CERR( "が与えられているとし、配列Bの条件P(B)を" );
  CERR( "「Bの長さ|B|がQ(|B|)かつ|B|<L+nを満たし、かつ任意の0<=l<=|B|-nに対し" );
  CERR( "　R_l(B_l,...,B_{l+n-1})が成り立つ。」" );
  CERR( "の論理積として定めます。" );
  CERR( "" );
  CERR( "例えば山型の部分列の数え上げ問題ではN>=3かつ(n,L)=(2,2)で" );
  CERR( "- Q(i)=「i=3」" );
  CERR( "- R_0(b_0,b_1)=「b_0<b_1」" );
  CERR( "- R_1(b_0,b_1)=「b_0>b_1」" );
  CERR( "と表されます。" );
  CERR( "" );
  if( num == num_temp++ ){
    CALL_AC( CountingRestrictedContinuousSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrictedDiscontinuousSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrictedSubPermutation );
  }
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "特にR_l(B)たちがgcdやmaxなどの羃等演算に関する等式で与えられる場合は、" );
  CERR( "不等式の方が扱いやすいのでゼータ変換／メビウス変換" );
  CERR( "\\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "を検討しましょう。" );
}

AC( CountingRestrictedContinuousSubArray )
{
  CERR( "P(B)を満たすAの連続部分列Bの数え上げは、" );
  CERR( "- R_lたちがlに依存しないならば尺取り法O(N)" );
  CERR( "- R_lたちがlに依存する場合、" );
  CERR( "  - O(N^2)が通りそうなら左端を固定した愚直探索" );
  CERR( "  - O(N^2)が通らなさそうならR_lたちの読み替え" );
  CERR( "を検討しましょう。" );
}

AC( CountingRestrictedDiscontinuousSubArray )
{
  CERR( "P(B)を満たすAの連続とは限らない部分列Bの数え上げは、" );
  CERR( "- n-1<=i<=max{j<=N|Q(j)}を満たす各i" );
  CERR( "- (0,1,...,N-1)の長さn-1の各部分列s" );
  CERR( "に対する" );
  CERR( "「長さiで、任意の0<=l<=i-nに対しR_l(B)を満たし、" );
  CERR( "　末尾n-1項がsに対応するAの部分列Bの個数dp[i][s]」" );
  CERR( "を管理するi,sに関する動的計画法" );
  CERR( "- 全順序でO(N log_2 N)が間に合いそうならば、通常の配列で二分探索" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence" );
  CERR( "- 疎な半順序でO((N+E)log_2 N)が間に合いそうならば、連想配列" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence\\Subwalk" );
  CERR( "- O(N + C^2 N^{1/2})が間に合いそうならば、順序集合の各要素c < dに対する" );
  CERR( "  「始端の値がc、終端の値がd以下である単調増加部分列の個数」を管理する" );
  CERR( "  C次上半行列を載せたモノイド平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid" );
  CERR( "を検討しましょう。" );
}

AC( CountingRestrictedSubPermutation )
{
  CERR( "P(B)を満たすAの部分順列Bの数え上げは、" );
  CERR( "- n-1<=|S|<=max{j<=N|Q(j)}を満たす(0,1,...,N-1)の部分集合S" );
  CERR( "- Sの長さn-1の各部分順列s" );
  CERR( "に対する" );
  CERR( "「任意の0<=l<=|S|-nに対しR_l(B)を満たし、末尾n-1項がsに対応し、」" );
  CERR( "　全体がSに対応するAの部分順列Bの個数dp[S][s]」" );
  CERR( "を管理するS,sに関する動的計画法を検討しましょう。" );
  CERR( "" );
  CERR( "sの網羅は[0,N)^{n-1}の全探策でもS内の順列探索と定数倍しか変わらないので" );
  CERR( "実装の速さを優先しましょう。" );
  CERR( "" );
  CERR( "Nが小さい場合は概算値" );
  CERR( "7! ≒ 5×10^3" );
  CERR( "8! ≒ 4×10^4" );
  CERR( "9! ≒ 4×10^5" );
  CERR( "10! ≒ 4×10^6" );
  CERR( "11! ≒ 4×10^7" );
  CERR( "12! ≒ 5×10^8" );
  CERR( "を参考に順列の全列挙" );
  CERR( "\\Mathematics\\Combinatorial\\Permutation" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "適宜ヤング図形との関係も検討しましょう。" );
  CALL_AC( CountingYoundDiagram );
}

AC( CountingGeneralRelationSubArray )
{
  ASK_YES_NO( "配列への格納順が関係ありますか？" );
  if( reply == "y" ){
    CERR( "半順序を構成しグラフの数え上げに帰着することを検討しましょう。" );
    CALL_AC( CountingGraph );
  } else {
    CERR( "（多重）集合やソートされた配列の数え上げに帰着することを検討しましょう。" );
    CALL_AC( CountingSubset );
  }
}

AC( CountingSubArrayImageArray )
{
  CERR( "入力で与えられる配列をAと置きます。" );
  CERR( "配列として等しいAの部分列のうち辞書式順序最小のものを数え上げる" );
  CERR( "部分列DPを検討しましょう。具体的には" );
  CERR( "「末尾が第i成分由来で辞書順最小なAの部分列の個数dp[i]」" );
  CERR( "「s=A[j]を満たすj<iの最大値last[i][s]」" );
  CERR( "の２つを管理するiに関する動的計画法を検討しましょう。" );
}

AC( CountingPermutation )
{
  ASK_NUMBER(
             "条件を満たす順列の数え上げ問題" ,
             "与えられた順列の部分列の数え上げ問題" ,
             "与えられた配列の部分順列（部分列の並び換え）の数え上げ問題"
             );
  if( num == num_temp++ ){
    CERR( "成分に属性があり、順列が属性に関する制約を持つ場合、まずは同属性の成分を" );
    CERR( "同一視した場合の並べ方の総数を求め、次に並べ方を固定した場合の順列の" );
    CERR( "個数を求める次元削減を検討しましょう。" );
    ASK_YES_NO( "Nが2羃に限られますか？" );
    if( reply == "y" ){
      CERR( "順列を順序付けに翻訳し、先頭N/2項と末尾N/2項の順序付けに帰着させる" );
      CERR( "再帰を検討しましょう。" );
    } else {
      CERR( "1やNの位置の候補を絞り込み、昇順または降順に残りの位置を確定させましょう。" );
    }
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrictedSubPermutation );
  }
}

AC( CountingString )
{
  ASK_NUMBER(
	     "条件を満たす文字列の数え上げ問題" ,
	     "与えられた文字列の部分文字列の数え上げ問題"
             );
  if( num == num_temp++ ){
    CALL_AC( CountingStringConditional );
  } else {
    CALL_AC( CountingSubString );
  }
}

AC( CountingStringConditional )
{
  CERR( "文字列は文字の配列とみなします。" );
  CALL_AC( CountingArrayConditional );
}

AC( CountingSubString )
{
  ASK_NUMBER(
	     "部分文字列から取得位置情報を落とした文字列全体の数え上げ問題" ,
	     "文字列一致に関する性質を満たす部分文字列の数え上げ問題" ,
	     "文字配置に関する性質を満たす部分文字列の数え上げ問題"
	     );
  if( num == num_temp++ ){
    CERR( "文字列を文字の配列とみなすことで、配列の問題に帰着させることができます。" );
    CALL_AC( CountingSubArrayImageArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingMatchingSubString );
  } else if( num == num_temp++ ){
    CALL_AC( CountingShapedSubString );
  }
}

AC( CountingMatchingSubString )
{
  CERR( "- 自分とマッチングする部分文字列の数え上げ問題はZアルゴリズム" );
  CERR( "  \\Utility\\String\\Z-Algorithm" );
  CERR( "- 回文である部分文字列の数え上げ問題は" );
  CERR( "  - O(N^2)が通りそうならば、尺取り法による前計算" );
  CERR( "    \\Utility\\String\\Palindrome" );
  CERR( "  - O(N^2)が通らなさそうならば、Manacherのアルゴリズムや" );
  CERR( "    ローリングハッシュで前計算" );
  CERR( "    https://snuke.hatenablog.com/entry/2014/12/02/235837" );
  CERR( "    \\Utility\\String\\RollingHash" );
  CERR( "を検討しましょう。" );
}

AC( CountingShapedSubString )
{
  CERR( "ABC（３文字が異なる）やAAB（先頭２文字が一致し３文字目が異なる）など" );
  CERR( "文字配置が指定された長さLの部分文字列の数え上げは" );
  CERR( "- O(26^L N)が通りそうならば山型配列と同様に" );
  CERR( "  「i文字目までに長さL以下の各文字列sが部分文字列として出現する個数dp[i][s]」" );
  CERR( "  を管理するiに関する動的計画法" );
  CERR( "- O(L 26^L log_2 N)が通りそうならば" );
  CERR( "  「各2羃区間Iに長さL以下の各文字列sが部分文字列として出現する個数dp[I][s]」" );
  CERR( "  を管理するIに関する分割統治法" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "分割統治法で用いるdp[I]は文字列全体のなすモノイドのモノイド環を" );
  CERR( "文字列配置の不適切な文字列やなくても復元可能な文字列全体の生成するイデアルで" );
  CERR( "割って得られる非可換環の空文字列係数が1であるもの全体のなす非可換乗法モノイドに" );
  CERR( "値を取るため、非可換モノイドで抽象化可能なBITやセグメント木を用いることも可能です。" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Monoid" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SegmentTree" );
}

AC( CountingMatrix )
{
  CERR( "H行W列の行列を考えます。行と列の制約を2進法に翻訳してbitごとに考えます。" );
  ASK_NUMBER(
             "各行と各列にちょうど１回ずつ1が現れる{0,1}値行列の数え上げ" ,
             "各行と各列に高々１回のみ1が現れる{0,1}値行列の数え上げ" ,
             "i行目の総和がx_i、j列目の総和がy_jに指定された行列の数え上げ"
             );
  if( num == num_temp++ ){
    CERR( "全単射H->Wと等価なのでその個数はH==W?H!:0です。" );
  } else if( num == num_temp++ ){
    CERR( "単射部分写像H-->Wと等価なのでその個数は" );
    CERR( "sum_{n<=min(H,W)} n! binom(H,n) binom(W,n)です。" );
  } else if( num == num_temp++ ){
    CERR( "各成分とxとyをD桁の2進法で表示し、繰り上がりを考慮して" );
    CERR( "d<D,h<=[H/2+1]*W,w<=[W/2+1]*Hに対する" );
    CERR( "dp[d][h][w]=" );
    CERR( "「2^dの位までの行の総和=(x%2^{d+1})+w*2^{d+1}、" );
    CERR( "  2^dの位までの列の総和=(y%2^{d+1})+h*2^{d+1}となる個数」" );
    CERR( "を管理する桁DP（O(D (W/2+1)^H (H/2+1)^W 2^{HW})）" );
    CERR( "を検討しましょう。" );
    CERR( "" );
    CERR( "なおsum(x)=sum(y)よりsum(w)=sum(h)なので、" );
    CERR( "必要ならば状態を１つ削減することが可能です。" );
  }
}

AC( CountingGraph )
{
  ASK_NUMBER(
             "付加構造付き木の数え上げ問題" ,
             "条件を満たす無向グラフの数え上げ問題" ,
             "条件を満たす有向グラフの数え上げ問題" ,
	     "与えられた木の分割の数え上げ問題" ,
	     "与えられたグラフの部分グラフの数え上げ問題" ,
             "与えられたグラフの彩色の数え上げ"
             );
  if( num == num_temp++ ){
    CALL_AC( CountingTree );
  } else if( num == num_temp++ ){
    CALL_AC( CountingUndirectedGraph );
  } else if( num == num_temp++ ){
    CALL_AC( CountingDirectedGraph );
  } else if( num == num_temp++ ){
    CALL_AC( CountingPartitionOfTree );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubgraph );
  } else if( num == num_temp++ ){
    CALL_AC( CountingGraphColouring );
  }
}

AC( CountingTree )
{
  ASK_NUMBER(
             "ラベル付き木" ,
             "二分木"
             );
  if( num == num_temp++ ){
    CERR( "ラベル付き無向木はケーリーの公式N^{N-2}で計算できます。" );
    CERR( "https://oeis.org/A000272" );
    CERR( "その他の付加構造付きの数え上げは" );
    CERR( "- 対称性に注目" );
    CERR( "- プリューファーコードの亜種に注目" );
    CERR( "などによりケーリーの公式から導出しましょう。" );
    CERR( "- 根付きのラベル付き無向木やラベル付き有向木は" );
    CERR( "  N^{N-1}" );
    CERR( "- 長さLのラベル付き部分パスグラフの与えられたラベル付き無向木は" );
    CERR( "  N^{N-L-1} * L" );
    CERR( "- 長さLの部分パスグラフとラベル付き無向木の組は" );
    CERR( "  ( L! / 2 ) * N^{N-L-1} * L" );
  } else if( num == num_temp++ ){
    CERR( "- 各ノードの枝に左右の区別があるNノードN+1葉の二分木は" );
    CERR( "  第Nカタラン数C(N)=(2N)!/((N+1)!N!)" );
    CERR( "  https://ja.wikipedia.org/wiki/カタラン数#カタラン数の意味" );  
  }
  CERR( "を検討しましょう。" );
}

AC( CountingUndirectedGraph )
{
  CERR( "- 円上の2N頂点に非交差かつ次数2な無向辺を張って得られる無向グラフは" );
  CERR( "  第Nカタラン数C(N)=(2N)!/((N+1)!N!)" );
  CERR( "  https://ja.wikipedia.org/wiki/カタラン数#カタラン数の意味" );  
  CERR( "- なもりグラフはサイクル（N!/(N-C)!）とそれ以外への分割（C^{N-C}）" );
  CERR( "を検討しましょう。" );
}

AC( CountingDirectedGraph )
{
  CERR( "- ラベル付き有向木（根付き木）はケーリーの公式の亜種N^{N-1}" );
  CERR( "  https://oeis.org/A000169" );
  CERR( "- K個のサイクルの和は第1種スターリング数s(N,K)" );
  CERR( "  https://スターリング数#組み合わせ数学における意味" );
  CERR( "を検討しましょう。" );
}

AC( CountingSubgraph )
{
  ASK_NUMBER(
             "誘導部分グラフの数え上げ問題" ,
             "一般の部分グラフの数え上げ問題"
             );
  CERR( "- 辺数3の閉路の個数は各頂点の２辺全探策" );
  if( num == num_temp++ ){
    CERR( "- 辺数2のパスグラフの数え上げはsum_v binom(deg(v),2)から" );
    CERR( "  辺数3の閉路の個数*3を引いた値" );
    CERR( "- 木の辺数3のパスグラフの数え上げは" );
    CERR( "  sum_u sum_{v in e[u]} (len(e[u])-1)*(len(e[v])-1)/2 " );
  } else if( num == num_temp++ ){
    CERR( "- 辺数Lの閉路の数え上げは深さ優先探索による長さL-1の経路全探策" );
    CERR( "- 辺数Lの木の数え上げは深さ優先探索による長さLの経路全探策" );
    CERR( "を検討しましょう。" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Path" );
  }
}

AC( CountingGraphColouring )
{
  CERR( "DAGの彩色の数え上げは端点から順に確定させていく動的計画法を" );
  CERR( "検討しましょう。状態としては" );
  CERR( "- 可能な数値そのもの" );
  CERR( "- 残り容量（容量-コスト）" );
  CERR( "などを検討しましょう。" );
  CERR( "" );
  CERR( "彩色に課された条件が複雑な場合、明次式に書き直してその正当性を" );
  CERR( "彩色の構築に帰着させて考察しましょう。" );
  CALL_AC( ConstructionColouring );
}

AC( CountingSubset )
{
  ASK_NUMBER(
             "要素を受け取る関数の部分和を固定した部分集合の数え上げ問題" ,
             "同型類を固定した部分グラフの数え上げ問題" ,
             "その他の部分集合の数え上げ問題" ,
             "部分集合への分割の数え上げ問題"
             );
  if( num == num_temp++ ){
    CERR( "要素に番号を振り、集合を配列とみなして部分和問題に帰着させましょう。" );
    CALL_AC( CountingSumFixedSubArray );
  } else if( num == num_temp++ ){
    AC( SubsetExhusiveSearch );
    CERR( "- bit演算についての条件が課された[0,2^N)の部分集合や" );
    CERR( "  集合演算についての条件が課された[0,N)の部分集合の族は、" );
    CERR( "  bit／要素ごとに分けて考察" );
    CERR( "- 各区間との共通部分の要素数の分布についての条件が課された[0,N)の" );
    CERR( "  部分集合は各始切片との共通部分の要素数の分布の条件に翻訳" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    AC( CountingPartitionOfSet );
  };
}

AC( CountingPartition )
{
  ASK_NUMBER(
             "配列の連続部分列への分割の数え上げ問題" ,
             "集合の部分集合への分割の数え上げ問題" ,
             "木の部分木への分割の数え上げ問題"
             );
  if( num == num_temp++ ){
    AC( CountingPartitionOfArray );
  } else if( num == num_temp++ ){
    AC( CountingPartitionOfSet );
  } else if( num == num_temp++ ){
    AC( CountingPartitionOfTree );
  }
}

AC( CountingPartitionOfArray )
{
  CERR( "dp[i] = 「第i成分までで打ち切った配列の分割の個数」" );
  CERR( "を管理するiに関する動的計画法を検討しましょう。" );
}

AC( CountingPartitionOfSet )
{
  CERR( "- 任意有限個の部分集合への排他的分割ならばベル数B(N)" );
  CERR( "  https://ja.wikipedia.org/wiki/ベル数" );
  CERR( "- 任意有限個の部分集合への非公差分割や、円上のN頂点の多角形分割や" );
  CERR( "  円上のN+2角形の三角形分割ならば第Nカタラン数C(N)=(2N)!/((N+1)!N!)" );
  CERR( "  https://ja.wikipedia.org/wiki/カタラン数" );
  CERR( "  https://ja.wikipedia.org/wiki/非交差分割" );
  CERR( "- K個の部分集合への排他的分割ならば第2種スターリング数s(N,K)" );
  CERR( "  \\Mathematics\\Combinatorial\\StirlingNumber\\SecondKind" );
  CERR( "  https://ja.wikipedia.org/wiki/スターリング数#組み合わせ数学における意味_2" );
  CERR( "を検討しましょう。" );
}

AC( CountingPartitionOfTree )
{
  CERR( "木を受け取る関数fが与えられているとします。" );
  CERR( "" );
  CALL_AC( FunctionOnTree );
  CERR( "F(P)が固定された時のPの数え上げ問題は" );
  CERR( "「第i成分までで切った時のF(P)=vを満たすPの個数dp[i][v]」" );
  CERR( "を管理するi,vに関する動的計画法（O(N^2 v_max×fの計算量)）" );
  CERR( "を検討しましょう。" );
}

AC( CountingMap )
{
  CERR( "第2種スターリング数をs(N,M)と表します。" );
  CERR( "\\Mathematics\\Combinatorial\\StirlingNumber\\SecondKind" );
  CERR( "- N元集合からM元集合への全単射はN==M?N!:0" );
  CERR( "- N元集合からM元集合への単射はN!*binom(M,N)" );
  CERR( "- N元集合からM元集合への全射はM!*s(N,M)" );
  CERR( "- N元集合の部分集合からM元集合への全単射はM!*binom(N,M)" );
  CERR( "- N元集合の部分集合からM元集合への単射はsum_c c!*binom(N,c)*binom(M,c)" );
  CERR( "- N元集合の部分集合からM元集合への全射はM!*s(N,M)+(M+1)!*s(N,M+1)" );
  CERR( "を検討しましょう。" );
}

AC( CountingStrategy )
{
  CERR( "なるべく簡単な操作に同値変形しましょう。" );
  CALL_AC( InterpretingSequenceOperation );
  ASK_NUMBER(
	     "不可逆な操作列の数え上げ問題" ,
	     "操作する対象全体の集合の数え上げ問題" ,
	     );
  if( num == num_temp++ ){
    CERR( "不可逆な操作は整礎半順序集合上の遷移とみなせます。" );
    CERR( "- １つの始点からの移動を考える場合は" );
    CERR( "  「各点iへの移動経路の個数dp[i]」" );
    CERR( "  を管理するiに関する動的計画法" );
    CERR( "- １つの終点への移動を考える場合は" );
    CERR( "  「各点iからの移動経路の個数dp[i]」" );
    CERR( "  を管理するiに関する動的計画法" );
  } else if( num == num_temp++ ){
    CERR( "操作対象を各非負整数iで適切に番号付けて" );
    CERR( "「i以下の番号の対象のみを考えた時の選択方法の個数dp[i]」" );
    CERR( "を管理するiに関する動的計画法" );
  }
  CERR( "を検討しましょう。" );
  ASK_YES_NO( "線形漸化式に帰着されますか？" );
  if( reply == "y" ){
    CALL_AC( ExplicitExpressionUnaryLinearRecursion );
    CERR( "を検討しましょう。" );
  }
}

AC( InterpretingSequenceOperation )
{
  ASK_NUMBER(
             "01列の操作" ,
             "単調増加列の操作" ,
             "一般の数列の操作"
             );
  if( num == num_temp++ ){
    CALL_AC( Interpreting01SequenceOperation );
  } else if( num == num_temp++ ){
    CALL_AC( InterpretingIncreasingSequenceOperation );
  } else if( num == num_temp++ ){
    CALL_AC( InterpretingGeneralSequenceOperation );
  }
}

AC( Interpreting01SequenceOperation )
{
  ASK_NUMBER(
             "1の個数が変わらない操作のみ" ,
             "2進法での繰り上がりなし加算" ,
             "2進法での加算／減算"
             );
  if( num == num_temp++ ){
    CERR( "0と1をswapさせていく操作の積み重ねに翻訳し、どのような積み重ねが" );
    CERR( "許されているかを考え、その操作の不変量や増減量を考えましょう。" );
    CERR( "- 10->01ならば、1つの閉じ括弧の深さが1増え、括弧列（各深さが正）が保たれる。" );
    CERR( "- 01->10ならば、1つの閉じ括弧の深さが1減る。" );
  } else if( num == num_temp++ ){
    CERR( "ライツアウトに翻訳しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "非負整数に翻訳しましょう。" );
  }
}

AC( InterpretingIncreasingSequenceOperation )
{
  CERR( "単調増加列は" );
  CERR( "- 非負階差数列" );
  CERR( "- 01列（1の個数で階差を表現）" );
  CERR( "- ヤング図形（マスの個数で値を表現し左右反転）" );
  CERR( "に翻訳しましょう。" );
  ASK_NUMBER(
             "1成分への正の加算のみ" ,
             "1成分への加算／減算" ,
             "1成分への正の減算のみ" ,
             "値の等しい隣接2成分への操作"
             );
  if( num == num_temp++ ){
    CERR( "1成分への+1を" );
    CERR( "- 01列の10->01" );
    CERR( "- ヤング図形に新たなマスを追加しそこに操作番号を記入、" );
    CERR( "  更に操作を逆順にし番号を反転することでヤング図形のマスの削除と" );
    CERR( "  操作番号書き込みに対応させることで標準ヤングタブローに帰着" );
    CERR( "と翻訳しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- 1成分への+1を01列の10->01" );
    CERR( "- 1成分への-1を01列の01->10" );
    CERR( "と翻訳しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "1成分への-1を" );
    CERR( "- 01列の01->10" );
    CERR( "- ヤング図形のマスを削除しそこに操作番号を記入" );
    CERR( "と翻訳しましょう。" );
  } else if( num == num_temp++ ){
    ASK_YES_NO( "同じ値の加算／減算を行いますか？" );
    if( reply == "y" ){
      CERR( "- 値の等しい隣接2成分への+1を01列の110->011" );
      CERR( "- 値の等しい隣接2成分への-1を01列の011->110" );
      CERR( "と翻訳しましょう。" );
    }
    ASK_YES_NO( "同じ値の受け渡しを行いますか？" );
    if( reply == "y" ){
      CERR( "- 値の等しい隣接2成分間の-1,+1は01列の0110->1001" );
      CERR( "- 値の等しい隣接2成分間の+1,-1は01列の1001->0110" );
      CERR( "と翻訳しましょう。" );
    }
  }
  CERR( "以下01列に翻訳して考えます。" );
  CALL_AC( Interpreting01SequenceOperation );
}

AC( InterpretingGeneralSequenceOperation )
{
  ASK_YES_NO( "距離の固定された2成分への操作ですか？" );
  if( reply == "y" ){
    CERR( "距離をDと置きます。D>1ならば成分番号をDで割った余りで配列をD個に" );
    CERR( "分割し、D=1に帰着させましょう。" );
    ASK_YES_NO( "同じ値の加算／減算を行いますか？" );
    if( reply == "y" ){
      CERR( "- 隣接2成分への+1を階差数列の-1,0,+1" );
      CERR( "- 隣接2成分への-1を階差数列の+1,0,-1" );
      CERR( "と翻訳しましょう。" );
    }
    ASK_YES_NO( "同じ値の受け渡しを行いますか？" );
    if( reply == "y" ){
      CERR( "- 隣接2成分への-1,+1を累積和の-1" );
      CERR( "- 隣接2成分への+1,-1を累積和の+1" );
      CERR( "と翻訳しましょう。" );
    }
  }
}

AC( CountingPath )
{
  ASK_NUMBER(
	     "格子点上の経路の数え上げ" ,
	     "可換群上の経路の数え上げ" ,
	     "一般のグラフ上の経路の数え上げ" ,
	     );
  if( num == num_temp++ ){
    CERR( "始点から各点への経路数に関する漸化式を立式しましょう。" );
    CERR( "例えばパスカルの三角形上の経路数は、そのままパスカルの三角形で与えられます。" );
    CERR( "- 経路数がある不変量にのみ依存する場合、不変量ごとに管理して計算量を削減" );
    CERR( "- 領域に対称性がある場合、始点からある点pへの経路数とpの対称点から終点への経路数" );
    CERR( "  の間の関係式を立式" );
    CERR( "を検討しましょう。" );
    CERR( "" );
    CERR( "領域から外に出る経路の数え上げは、出る直前の経路に帰着させましょう。" );
    CERR( "適宜カタラン数やヤング図形との関係も検討しましょう。例えば" );
    CERR( "N×N格子で左下から右上まで対角線を跨がず最初に右へ行く最短経路の個数は" );
    CERR( "第Nカタラン数C(N)=(2N)!/((N+1)!N!)です。" );
    CALL_AC( CountingYoundDiagram );
  } else if( num == num_temp++ ){
    CERR( "高々N回の移動で目的地に到達して終了する経路数は、N以下の各非負整数iに対し" );
    CERR( "ちょうどi回の移動で最初に到達する経路数p(i)の総和です。" );
    CERR( "従って(p(i))_iの母関数f(x)の累積和f(x)/(1-x)の計算に帰着されます。" );
    CERR( "ちょうどi回の移動で元の位置戻る経路数をq(i)、目的地にいる経路数をr(i)回" );
    CERR( "とすると(q(i))_iと(r(i))_iの母関数g(x)とh(x)はfg=hを満たすので、" );
    CERR( "f(x)/(1-x)=h(x)/((1-x)g(x))の係数をボスタン森法で求めましょう。" );
    CERR( "Mathematics\\Polynomial\\BostanMori" );
  } else if( num == num_temp++ ){
    CERR( "ループの不能な有向グラフは整礎なので、各点pごとに" );
    CERR( "-「pが探索されたか」を表すbool値配列" );
    CERR( "-「pへの辺を持つ未探索点の個数」を表す配列" );
    CERR( "を管理し毎回後者を全探策することでO(|V|^2+|E|)で全ての点を探索できます。" );
  }
}

AC( CountingTiling )
{
  ASK_NUMBER(
	     "隣接成分と異なる色で塗り分ける問題" ,
	     "与えられた図形で描画可能になるように塗り分ける問題" ,
	     "与えられた条件に従って塗り分け可能になるように図形で描画する問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingColouringDistinct );
  } else if( num == num_temp++ ){
    CALL_AC( CountingColouringDrawable );
  } else if( num == num_temp++ ){
    CALL_AC( CountingTilingPaintable );
  }
}

AC( CountingColouringDistinct )
{
  CALL_AC( CountingColouring );
  CERR( "- 群の作用による同一視があるならば、コーシー・フロベニウスの補題" );
  CERR( "  https://ja.wikipedia.org/wiki/コーシー・フロベニウスの補題" );
  CERR( "を検討しましょう。" );
}

AC( CountingColouring )
{
  CERR( "- 塗り分ける図形群の外周や頂点に位置する図形やの個数が少ないか" );
  CERR( "  色の種類数が少ないならば、外周や頂点の図形群の塗り分けを固定することで" );
  CERR( "  一廻り小さい図形群に対する数え上げとの関係式を導出し、" );
  CERR( "  サイズに関する動的計画法" );
}

AC( CountingColouringDrawable )
{
  CERR( "描画可能性を簡単な条件に翻訳し、その条件を満たす塗り分けを" );
  CERR( "数え上げましょう。" );
  ASK_YES_NO( "重なりを許して図形を置く描画方法ですか？" );
  if( reply == "y" ){
    CALL_AC( DecisionDrawabilitySameSizeOverdrawn );
  } else {
    CALL_AC( DecisionDrawabilitySameSizeUnoverdrawn );
  }
}

AC( CountingTilingPaintable )
{
  CERR( "塗り分けごとに図形の描画方法が一意に定まるならば、" );
  CERR( "塗り分け方法の同値類として描画方法を数え上げをましょう。" );
  CERR( "- 同値類の要素数が一定ならば単純な商" );
  CERR( "- 群の作用による同一視があるならば、コーシー・フロベニウスの補題" );
  CERR( "  https://ja.wikipedia.org/wiki/コーシー・フロベニウスの補題" );
  CERR( "で商集合を計算しましょう。条件つきの塗り分けは" );
  CERR( "- グリッドの部分集合のマスや辺の塗り分けは、左下から単純な2重ループ" );
  CALL_AC( CountingColouring );
  CERR( "を検討しましょう。" );
}

AC( CountingYoundDiagram )
{
  CERR( "標準ヤングタブロー（行／列ともに狭義単調増加になるような全単射）と" );
  CERR( "値の上限つき半標準ヤングタブロー（行に広義単調増加を許したもの）" );
  CERR( "の個数はそれぞれフック長公式とフックcontent公式で計算できます。" );
  CERR( "\\Mathematics\\Combinatorial\\YoungDiagram" );
  CERR( "https://ncatlab.org/nlab/show/semistandard+Young+tableau#HookContentFormula" );
  CERR( "- 標準ヤングタブローと行番号の列の対応" );
  CERR( "  - 特に2×Nの標準ヤングタブローは対角線を跨がないN×Nの経路に対応し、" );
  CERR( "  - その個数は第Nカタラン数C(N)=(2N)!/((N+1)!N!)で与えられる。" );
  CERR( "- 像が始切片である半標準ヤングタブローと(行番号,重み=連続度)の列の対応" );
  CERR( "  - 特に像が始切片2×Nの半標準ヤングタブローは対角線を跨がないN×Nの" );
  CERR( "    歩幅正整数の経路に対応する。" );
  CERR( "- N行の半標準ヤングタブローは無限の広さのグリッド内の非交叉なパスN本の組" );
  CERR( "  に対応し、その個数はLindstrom-Gessel-Viennotの補題で与えられる。" );
  CERR( "  https://en.wikipedia.org/wiki/Lindstr%C3%B6m%E2%80%93Gessel%E2%80%93Viennot_lemma#Statement" );
  CERR( "- 半標準ヤングタブローと三角形状のGelfand-Tsetlin pattern" );
  CERR( "  （二方向に広義単調増大な列）との対応" );
  CERR( "  https://www.symmetricfunctions.com/gtpatterns.htm#gtpatternsAsSSYT" );
  CERR( "- skew半標準ヤングタブローと三角形状のGelfand-Tsetlin pattern" );
  CERR( "  （二方向に広義単調増大な列）との対応" );
  CERR( "  https://www.symmetricfunctions.com/gtpatterns.htm#gtpatternsAsSSYT" );
  CERR( "- 型の等しい標準ヤングタブローの組と順列のRS対応" );
  CERR( "  https://en.wikipedia.org/wiki/Robinson%E2%80%93Schensted_correspondence" );
  CERR( "- 型の等しい半標準ヤングタブローの組と非負整数係数行列のRSK対応" );
  CERR( "  https://en.wikipedia.org/wiki/Robinson%E2%80%93Schensted%E2%80%93Knuth_correspondence" );
  CERR( "を検討しましょう。" );
}

AC( CountingParenthesisSequence )
{
  ASK_YES_NO( "ワイルドカード*に関する問題ですか？" );
  if( reply == "y" ){
    CALL_AC( CountingWildCardedParenthesisSequence );
  } else {
    CALL_AC( CountingPlainParenthesisSequence );
  }
}

AC( CountingWildCardedParenthesisSequence )
{
  CERR( "()*の列で*を()に変更して閉じたカッコ列を作れる必要十分条件は、" );
  CERR( "*を前から(に、後ろから)に変えて(と)をN/2個ずつにした時に" );
  CERR( "閉じたカッコになることです。" );
  CERR( "" );
  CERR( "従ってそのような()*の列は()[]の列であって" );
  CERR( "(1) [を(、]を)に変更すると閉じたカッコ列になる。" );
  CERR( "(2) ]より後に[が来ない。" );
  CERR( "を満たすもの（閉じた()[]列）と等価です。" );
  ASK_NUMBER(
             "入力で長さNのみが与えられる数え上げ問題" ,
             "入力で長さNのワイルドカード付き文字列が与えられる数え上げ問題"
             );
  if( num == num_temp++ ){
    CERR( "- 閉じたカッコ列に変更可能なワイルドカード付き文字列の個数は、" );
    CERR( "  閉じた()[]の列の数え上げに翻訳して動的計画法（O(N^2)）" );
    CERR( "- 閉じた()[]列に変更可能なワイルドカード付き文字列の個数は、" );
    CERR( "  閉じた()[]の列の数え上げに翻訳して動的計画法（O(N^2)）" );
    CERR( "を検討しましょう。" );
  } else {
    CERR( "- *を()に変更して閉じたカッコ列にする方法の個数は、" );
    CERR( "  dp[i] = 「(の個数-)の個数==i」を満たす変更方法の個数" );
    CERR( "  を管理するiに関する動的計画法（O(N^2)）" );
    CERR( "- *を[]に変更して閉じた()[]列にする方法の個数は、" );
    CERR( "  dp[i][b] = 「([の個数-)]の個数==i」かつ「]が出現済み<=>b」を" );
    CERR( "              満たす変更方法の個数" );
    CERR( "  を管理するiに関する動的計画法（O(N^2)）" );
    CERR( "を検討しましょう。" );
  }
}

AC( CountingPlainParenthesisSequence )
{
  CERR( "- 2N文字の閉じたカッコ列の個数は第Nカタラン数C(N)=(2N)!/((N+1)!N!)" );
  CERR( "- 3N文字の閉じた(,)の列の個数はファス・カタラン数" );
  CERR( "  A_N(3,1)=(3N)!/((2N+1)!N!)" );
  CERR( "  https://en.wikipedia.org/wiki/Fuss%E2%80%93Catalan_number" );
  CERR( "- (K+2)N文字の閉じた引数K+1関数適用のカッコ列の個数はファス・カタラン数" );
  CERR( "  A_N(K+2,1)=((K+2)N)!/(((K+1)N+1)!N!)" );
  CERR( "  https://en.wikipedia.org/wiki/Fuss%E2%80%93Catalan_number" );
  CERR( "  https://yukicoder.me/problems/no/3145/editorial" );
  CERR( "- O(N^2)が間に合いそうならば、" );
  CERR( "  - 長さと右端の深さごとに答えを管理する括弧列DP" );
  CERR( "  - (N+1)\times(N+1)のグリッド上の経路に翻訳" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Grid\\CountDirectedPath" );
  CERR( "を検討しましょう。" );
}

AC( Solving )
{
  ASK_NUMBER(
	     "１つの方程式f(x,y,...) = c" ,
	     "M個の方程式f(x[a[i]],C^{d[i]}x[b[i]]) = c[i]" ,
	     "M個の方程式sum_{j=a[i]}^{b[i]} C^{j-a[i]} x[j] = c[i]" ,
	     "その他の方程式"
	     );
  if( num == num_temp++ ){
    CERR( "- 楕円型の不定方程式ならば、" );
    CERR( "  - 有界な領域を全探策" );
    CERR( "  - 片方の変数を固定して整数の範囲で実数根の近傍計算" );
    CERR( "- 放物型の不定方程式ならば、平方完成で変数変換して得られる2変数を" );
    CERR( "  掃き出し、１変数ごとに決定" );
    CERR( "- 双曲型の不定方程式ならば、" );
    CERR( "  - 非零定数倍と移項で変数を含む積=定数の形になれば定数の約数列挙" );
    CERR( "  - ならなければペル方程式に帰着" );
    ASK_YES_NO( "f(x,y,...) = h(g(x),g(y),...)の形ですか？" );
    if( reply == "y" ){
      CERR( "f,gを別々に以下の手順で前計算" );
      CERR( "- まず各b in im(g)に対しf(a,b) = cを満たすa in im(g)全体を前計算する。" );
      CERR( "- 次に|dom(g)| = N、max im(g) = Mとして、各y in im(g)に対する" );
      CERR( "  逆像の代表元を管理するg_inv[y]を" );
      CERR( "  - O(N)が間に合いそうならばunordered_map::g_inv[g[x]]=x" );
      CERR( "  - O(M+N)が間に合いそうならば配列::g_inv[g[x]]=x" );
      CERR( "  - x,yに制限h(x)<h(y)がある場合はh(x)の上限cについてループして" );
      CERR( "    g_inv[g(x)]=xしていき、それと並行してyをc<h(y)の範囲で全探索" );
      CERR( "  により管理する。" );
      CERR( "- 最後に各yごとにf(a,g(y)) = cを満たす各a in im(g)に対しa = g(x)を満たす" );
      CERR( "  xをg_inv[a]として与える。" );
      CERR( "を検討しましょう。" );
    }
  } else if( num == num_temp++ ){
    CALL_AC( SolvingBinaryEquations );
  } else if( num == num_temp++ ){
    CERR( "累積和sum_{j=i}^{N} C^{j-i} x[j]を新たに変数X[i]と置くことで" );
    CERR( "M個の方程式X[a[i]]-C^{b[i]-a[i]+1}X[b[i]+1] = c[i]" );
    CERR( "に帰着されます。これはf(x,y)=x-yと置くと" );
    CERR( "M個の方程式f(X[a[i]],d^{b[i]-a[i]+1}X[b[i]+1]) = c[i]" );
    CERR( "に他なりません。" );
    CALL_AC( SolvingBinaryEquations );
  } else if( num == num_temp++ ){
    CERR( "- 単調関数は二分探索" );
    CERR( "- 可微分関数はニュートン法" );
    CERR( "- 連立一次方程式は掃き出し法" );
    CERR( "- 変数の依存関係が閉路を持たないならば逆順に決定" );
    CERR( "を検討しましょう。" );
  }
}

AC( SolvingBinaryEquations )
{
  CERR( "f(x,C^j -)かf(-,C^j y)が単射であるとします。" );
  CERR( "- O(BMf(BN) + BN log B)が間に合いそうならば素集合データ構造" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "- O(BM + BN log B)が間に合いそうならば幅／深さ優先探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch" );
  CERR( "- O(Mf(N) + N)が間に合いそうでf(x,y)=x-yかつC=1ならば" );
  CERR( "  ポテンシャル付き素集合データ構造" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "を検討しましょう。" );
}

AC( Query )
{
  ASK_NUMBER(
	     "範囲更新／取得クエリ問題" ,
	     "範囲更新／数え上げクエリ問題" ,
	     "範囲更新／区間の部分列をわたる総和クエリ問題" ,
	     "範囲更新／部分列比較クエリ問題" ,
	     "2変数関数の計算クエリ問題（範囲更新なし区間和計算など）" ,
	     "3変数関数の計算クエリ問題（範囲更新なしf(A[i],x)の区間和計算など）" ,
	     "時系列変化のクエリ問題（時刻に関する配列値関数の区間取得など）" ,
             "グラフのクエリ問題" ,
             "集合のクエリ問題" ,
             "連結リストのクエリ問題"
	     );
  if( num < 4 ){
    CALL_AC( QueryDecomposition );
  }
  if( num == num_temp++ ){
    ASK_NUMBER(
               "配列クエリ" ,
               "グラフクエリ"
               );
    if( num == num_temp++ ){
      CALL_AC( QueryArray );
    } else if( num == num_temp++ ){
      CALL_AC( QueryGraph );
    }
  } else if( num == num_temp++ ){
    CALL_AC( QueryCounting );
  } else if( num == num_temp++ ){
    CALL_AC( QuerySubsequenceSum );
  } else if( num == num_temp++ ){
    CALL_AC( QueryString );
  } else if( num == num_temp++ ){
    CALL_AC( QueryTwoAryFunction );
  } else if( num == num_temp++ ){
    CERR( "各クエリで区間[l,r]とパラメータtが与えられ、２変数関数fを用いて" );
    CERR( "sum(i=l;i<=r;i++) f(A[i],t)と表される値を答えるとします。" );
    CERR( "g(t) = (f(A[i],t))_iと定めることで時系列変化に帰着されます。" );
    CERR( "" );
    CALL_AC( QueryTimeSeriesChange );
  } else if( num == num_temp++ ){
    CALL_AC( QueryTimeSeriesChange );
  } else   if( num == num_temp++ ){
    CALL_AC( QueryGraph );
  } else if( num == num_temp++ ){
    CALL_AC( QuerySet );
  } else if( num == num_temp++ ){
    CERR( "クエリを先読みし、予め成分の挿入箇所を特定しておきましょう。" );
    CERR( "その後あらためてクエリを処理します。挿入クエリを1加算に翻訳し、" );
    CERR( "データ構造に乗せましょう。" );
    CALL_AC( QueryArray );
  }
}

AC( QueryDecomposition )
{
  ASK_YES_NO( "区間取得クエリの区間が全体に限られる場合に解けますか？" );
  if( reply == "y" ){
    CERR( "配列を" );
    CERR( "- 平方分割" );
    CERR( "- 配列をセグメント木の要領で2羃長に分解" );
    CERR( "で小さい区間全体に帰着して解きましょう。" );
  };
  ASK_YES_NO( "更新クエリがない場合に解けますか？" );
  if( reply == "y" ){
    CERR( "クエリを平方分割し、" );
    CERR( "- 分割の境目までは更新クエリを適用せずに記録して" );
    CERR( "  更新クエリがない場合の取得クエリを計算し、" );
    CERR( "  更新クエリがある場合とのズレを計算" );
    CERR( "- 分割の境目では記録した更新クエリを全て適用し、記録をリセット" );
    CERR( "で更新クエリがない場合に帰着させましょう。" );
  };
}

AC( QueryArray )
{
  CERR( "配列上のクエリと整合的な代数構造を見付けるためには、" );
  CERR( "区間取得クエリを２つの区間のデータから計算し、必要なデータを特定して" );
  CERR( "それらの演算を計算しましょう。" );
  ASK_NUMBER(
	     "可換群構造+を使う問題" ,
	     "全順序構造<=を使う問題" ,
	     "可換羃等モノイド構造∨を使う問題" ,
	     "モノイド構造*を使う問題" ,
	     "非結合的マグマ構造*を使う問題" ,
	     "集合へのマグマ作用(*,\\cdot)を使う問題" ,
	     "集合への可換マグマ作用(*,\\cdot)を使う問題" ,
	     "モノイドへのマグマ作用(+,\\cdot)を使う問題" ,
	     "序数を扱う問題" ,
	     "区間の像の要素数を扱う問題" ,
	     "区間と逆像の共通部分の要素数を扱う問題" ,
	     "取得クエリの区間幅に制限のある問題" ,
	     "2引数関数による区間max／min更新を使う問題" ,
	     "距離関数と定数の和による区間min更新を使う問題" ,
	     "定数とのmaxを取った値の区間演算取得を使う問題" ,
             "終切片代入更新と末尾挿入と関数適用の総和を扱う問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryArrayAbelianGroup );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayTotalOrder );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayCommutativeIdempotentMonoid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMonoid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayNonAssociativeMagma );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMagmaSet );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayCommutativeMagmaSet );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMagmaMonoid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayOrder );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayImageSize );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayInverseImageSize );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayBoundedInterval );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMaxLinearFunction );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMinDistance );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMaxConstant );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayFinalSegmentSetFunctionApply );
  }
}

AC( QueryArrayAbelianGroup )
{
  CERR( "- 加算／全更新後の一点取得O(1)のみが必要ならば階差数列" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence" );
  CERR( "- 加算／全更新なしで区間取得O(1)のみが必要ならば累積積" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProd" );
  CERR( "- 一点加算O(log N)／一点代入O(log N)／区間取得O(log N)が必要ならばBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "- 区間加算O(log N)／一点代入O(log N)／区間取得O(log N)が必要ならば" );
  CERR( "  区間加算BIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\InteralAdd" );
  CERR( "- 一点加算O(1)／一点代入O(√N)／区間取得O(√N)が必要ならば平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition" );
  CERR( "- 一点加算O(1)／区間加算O(√N)／一点代入O(1)／一点取得O(1)が必要ならば" );
  CERR( "  可換双対平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual\\Commutative" );
  CERR( "- 一点加算O(1)／区間加算O(√N)／一点代入O(1)／一点取得O(1)／区間取得O(√N)" );
  CERR( "  が必要ならば区間加算平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\IntervalAdd" );
  CERR( "- 区間代入O(√N)／一点取得O(1)／区間取得O(√N)が必要ならば区間代入モノイド平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid\\IntervalSet" );
  CERR( "- 区間加算O(√N)／区間代入O(√N)／一点取得O(1)／区間取得O(√N)が必要ならば" );
  CERR( "  区間乗算遅延平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\LazyEvaluation\\IntervalMultiply" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayTotalOrder )
{
  CERR( "max／minは可換羃等モノイド構造に一般化されます。" );  
  CERR( "- 区間乗算O(log N)／更新後の一点取得O(1)が必要ならば" );
  CERR( "  区間をソートして集合管理の差分計算を行うイベントソート" );
  CERR( "- 長さKの区間取得合計O(N)が必要ならばスライド最大／最小化" );
  CERR( "  \\Mathematics\\Combinatorial\\SlidingMinimalisation" );
  CALL_AC( QueryArrayCommutativeIdempotentMonoid );
  CERR( "" );
  CERR( "またq個目のクエリを時刻qのイベントとみなすことで、max／minによる時系列更新と" );
  CERR( "みなします。" );
  CALL_AC( QueryTimeSeriesRangeChangeMax );
}

AC( QueryArrayCommutativeIdempotentMonoid )
{
  CERR( "- 一点乗算O(log N)／一点代入O((log N)^2)／区間取得O(log N)が必要ならば" );
  CERR( "  区間maxBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
  CERR( "- 一点乗算O(1)／区間乗算O(√N)／一点代入O(√N)／一点取得O(1)が必要ならば" );
  CERR( "  可換双対平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual\\Commutative" );
  CERR( "- 一点乗算O(1)／区間乗算O(log N)／一点代入O(log N)／一点取得O(log N)" );
  CERR( "  が必要ならば可換双対セグメント木" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SegmentTree\\Dual\\Commutative" );
  CERR( "- 区間取得O(1)が必要ならばSparse TableやDisjoint Sparse Table" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\DisjointSparseTable" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayMonoid )
{
  CERR( "- 一点代入O((log N)^2)／区間取得O(log N)が必要ならばモノイドBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Monoid" );
  CERR( "- 区間代入O(√N)／一点取得O(1)／区間取得O(√N)が必要ならば" );
  CERR( "  区間代入モノイド平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid\\IntervalSet" );
  CERR( "- 一点乗算O(1)／一点代入O(√N)／一点取得O(1)／区間取得O(√N)が必要ならば" );
  CERR( "  可換モノイド平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid\\Commutative" );
  CERR( "- 一点乗算O(1)／区間乗算O(√N)／一点代入O(√N)／一点取得O(1)／区間取得O(√N)" );
  CERR( "  が必要ならば区間乗算可換モノイド平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid\\Commutative\\IntervalMultiply" );
  CERR( "- 一点代入O(log N)／区間取得O(log N)が必要ならばセグメント木" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SegmentTree" );
  CERR( "- 区間取得O(1)が必要ならばDisjoint Sparse Table" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\DisjointSparseTable" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayNonAssociativeMagma )
{
  CERR( "- 写像のコード化によるモノイドへの帰着" );
  CERR( "  \\Mathematics\\Function\\Encoder" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "モノイドに対しては" );
  CALL_AC( QueryArrayMonoid );
}

AC( QueryArrayMagmaSet )
{
  CERR( "- 区間作用O(√N)／一点代入O(√N)／一点取得O(1)が必要ならば双対平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayCommutativeMagmaSet )
{
  CERR( "- 区間作用O(√N)／一点代入O(√N)／一点取得O(1)が必要ならば双対平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual" );
  CERR( "- 一点作用O(1)／区間作用O(√N)／一点代入O(√N)／一点取得O(1)が必要ならば" );
  CERR( "  可換双対平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual\\Commutative" );
  CERR( "- 一点作用O(1)／区間作用O(log N)／一点代入O(log N)／一点取得O(log N)" );
  CERR( "  が必要ならば可換双対セグメント木" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SegmentTree\\Dual\\Commutative" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayMagmaMonoid )
{
  CERR( "- 区間作用O(√N)／区間乗算O(√N)／区間代入O(√N)／一点取得O(1)／区間取得O(√N)" );
  CERR( "  が必要ならば遅延評価平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\LazyEvaluation" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayCommutativeMagmaMonoid )
{
  CERR( "- 区間作用O(√N)／区間代入O(√N)／一点取得O(1)／区間取得O(√N)が必要ならば" );
  CERR( "  遅延評価平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\LazyEvaluation" );
  CERR( "- 区間作用O(√N)／区間乗算O(√N)／区間代入O(√N)／一点取得O(1)／区間取得O(√N)" );
  CERR( "  が必要ならば区間乗算遅延評価平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\LazyEvaluation" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayOrder )
{
  CERR( "- 始切片内での一点序数取得O(log N)／序数実現値取得O(log N)が必要ならば" );
  CERR( "  右端の大きさでクエリをソートしてBITで像を管理し" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "  - 一点序数取得は平面走査" );
  CERR( "  - 序数実現値取得は平面走査＋二分探索" );
  CERR( "- 区間での序数実現点取得O(ord log N)が必要ならば区間maxBITで" );
  CERR( "  区間最大／最小値＋二分探索で区間を分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayImageSize )
{
  CERR( "区間の像の要素数取得が必要ならばMoのアルゴリズム（O((N+Q)√N)）" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayInverseImageSize )
{
  CERR( "q番目のクエリで共通部分を取る集合をS_qと置きます。" );
  CERR( "- A_iがS_qに属すi全体の集合I_qの構築が高速に可能でかつO(Q log N)が" );
  CERR( "  間に合いそうならば、I_qと区間の共通部分を二分探索で計算");
  CERR( "- A_iがS_qに属すq全体の集合Q_sの構築が高速に可能でかつ各区間内でのQ_sの濃度の" );
  CERR( "  上限をCとして、" );
  CERR( "  - O(NC+Q log Q)が間に合いそうならば、オフライン累積積で個数取得" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativePrpdict\\Offline" );
  CERR( "  - O(C(N+Q)√N)が間に合いそうならばMoのアルゴリズムで連想配列の累積和計算" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayBoundedInterval )
{
  CERR( "取得クエリの区間幅の上限をLと置きます。" );
  CERR( "- O(Q(√N+L))が間に合いそうならば、双対平方分割による区間更新＋一点取得" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Dual" );
  CERR( "- 更新クエリがなく区間幅がLで一定でO(N+QL)が間に合いそうならば、" );
  CERR( "  L-1個ずつにバケット分割しそれぞれで始切片と終切片の区間取得値を前計算し" );
  CERR( "  取得クエリの区間が跨ぐ２つの区間の値をO(L)でマージ" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayMaxLinearFunction )
{
  CERR( "- 最小値を最大値に帰着させるには、二分探索が不要であればReversed<T>を、" );
  CERR( "  二分探索が不要であれば-1倍を合成しましょう。" );
  CERR( "  \\Utility\\Reverse" );
  CERR( "- 一次関数や支配関係を満たすより一般の2パラメータ関数階層による" );
  CERR( "  全体max更新O(log N)／一点取得O(log N)が必要ならばConvex Hull Trick" );
  CERR( "  \\Mathematics\\Function\\MaxTwoAryHierarchy" );
  CERR( "- 傾きの候補がC個の一次関数による区間min更新O(N^{1/2})／一点取得O(C)が" );
  CERR( "  必要ならば等比数列min更新双対平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Dual\\GeometricProgressionMin" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayMinDistance )
{
  CERR( "距離関数と定数の和による区間min更新は傾き±1の一次関数による区間min更新" );
  CERR( "に他なりません。" );
  CALL_AC( QueryArrayMaxLinearFunction );
}

AC( QueryArrayMaxConstant )
{
  ASK_NUMBER(
             "永続的な全体max更新を行う。" ,
             "一時的な区間max更新を行う。" ,
             );
  if( num == num_temp++ ){
    CALL_AC( QueryTimeSeriesChangeMax );
  } else {
    CERR( "クエリ処理を行う配列をAと置きます。区間[L,R]を[0,R]-[0,L-1]に翻訳し、" );
    CERR( "始切片に帰着させます。始切片[0,R]がR昇順になるようクエリソートし、" );
    CERR( "Aによる[0,R]の像を、配列の値そのもの（resp. 1）を重複度とする" );
    CERR( "多重集合として管理し、その区間要素数取得で処理しましょう。" );
    CERR( "\\Mathematics\\SetTheory\\Line\\Bounded\\Compressed\\Multisubset" );
  }
}

AC( QueryArrayFinalSegmentSetFunctionApply )
{
  CERR( "更新する配列をAとして、２変数関数fに対するf(A[i],i)の総和c(A)を考えます。" );
  CERR( "更新する配列を連長圧縮してvector<pair<U,int>>で管理することで、" );
  CERR( "- 終切片代入は合計O(N+Q)" );
  CERR( "- 末尾挿入はO(1)" );
  CERR( "で処理可能です。並行してc(A)の更新を適宜他のデータ構造と合わせて行いましょう。" );
  CERR( "例えばc(A)が他の配列との内積であれば、他の配列をBITなどで管理して" );
  CERR( "区間取得を行うことで終切片代入時のc(A)の更新を高速に行えます。" );
}

AC( QueryGraph )
{
  ASK_NUMBER(
             "木クエリ（森クエリは木クエリに帰着）" ,
             "グリッドクエリ" ,
             "一般のグラフクエリ"
             );
  if( num == num_temp++ ){
    CALL_AC( QueryTree );
    CERR( "" );
  } else if( num == num_temp++ ){
    CALL_AC( QueryGrid );
    CERR( "" );
  } else if( num == num_temp++ ){
    // 候補なし
  }
  CALL_AC( QueryGeneralGraph );
}

AC( QueryTree )
{
  ASK_YES_NO( "木の部分集合の管理（追加／削除／部分木との共通部分の要素数取得）ですか？" );
  if( reply == "y" ){
    CERR( "各点に0,1を乗せることで一点更新と部分木総和取得に帰着されます。" );
  }
  ASK_YES_NO( "木の部分集合の連結包の管理ですか？" );
  if( reply == "y" ){
    CALL_AC( ExplicitExpressionConnectedHullInTree );
  }
  CERR( "- 木上の階差数列で、可換群構造に関する部分木加算O(1)／全更新後の一点取得O(1)" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence" );
  CERR( "- 木上の累積和で、可換群構造に関する部分木総和取得O(1)" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProduct\\Tree" );
  CERR( "- 全方位木DPで、モノイド構造に関する各部分木総乗取得O(N)" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Tree" );
  CERR( "- ダブリングで、トポロジカルソートされた頂点番号未満の最近祖先取得O(log N)" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Tree" );
  CERR( "- 重み付きLCAで、モノイド構造に関するパス総乗取得O(log N)" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Tree\\Weighted" );
  CERR( "- EulerTourとDisjointSparseTableにより前処理O(N log N)で" );
  CERR( "  LCAや距離の計算O(1)" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\DepthFirstSearch\\Tree\\LCA\\DST" );
  CERR( "- EulerTourかHL分解で配列化して、" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\DepthFirstSearch\\Tree\\EulerTour" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\DepthFirstSearch\\Tree\\HLDecomposition" );
  CERR( "  - IntervalAddBITで、可換群構造に関する一点更新O(log N)" );
  CERR( "    部分木加算O(log N)／部分木総和取得O(log N)" );
  CERR( "    \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\BIT\\IntervalAdd" );
  CERR( "  - IntervalMultiplyLazySqrtDecompositionで、モノイド構造に関する" );
  CERR( "    一点更新O(√N log N)／部分木加算O(√N log N)" );
  CERR( "    基点付きマグマの部分木作用O(√N log N)／部分木総乗取得O(√N log N)" );
  CERR( "    \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Lazy\\IntervalMultiply" );
  CERR( "を検討しましょう。" );
}

AC( QueryGrid )
{
  CERR( "- 可換群構造に関する矩形加算O(1)／全更新後の一点取得O(1)が必要ならば" );
  CERR( "  二次元階差数列" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence\\TwoDimentioal" );
  CERR( "- 可換群構造に関する矩形取得O(1)が必要ならば二次元累積和" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProduct\\TwoDimentioal" );
  CERR( "- 可換群構造に関する矩形加算O(1)／全更新後の矩形取得O(1)が必要ならば" );
  CERR( "  二次元階差数列と二次元累積和の併用" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence\\TwoDimentioal" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProduct\\TwoDimentioal" );
  CERR( "- 可換群構造に関する矩形加算O(log H log W)／矩形取得O(log H log W)が" );
  CERR( "  必要ならば二次元BIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\BIT\\TwoDimentioal" );
  CERR( "- 矩形Max更新O(H√(W log W))／矩形取得O(H√(W log W))が必要ならば" );
  CERR( "  一次元区間max更新平方分割の愚直並列による二次元化" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\IntervalSetMax" );
  CERR( "- 差分計算が高速に可能ならばMoのアルゴリズム" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
  CERR( "を検討しましょう。" );
}

AC( QueryGeneralGraph )
{
  CERR( "以下グラフの頂点数をV、辺の本数をE、クエリ数をQと置きます。" );
  CERR( "クエリを跨ぐ更新を「永続的」、１クエリごとにリセットされる更新を" );
  CERR( "「一時的」と表現します。" );
  CERR( "- 辺の永続的追加更新＋連結成分取得でO(V+(E+Q)α(V))が間に合いそう" );
  CERR( "  ならばUnionFind" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "- 辺の一時的追加更新＋連結成分取得でO(V+E+Q)が間に合いそうならば" );
  CERR( "  幅優先探索で連結成分前計算" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "- 辺の永続的削除更新＋連結成分取得でO(V+(E+Q)α(V))が間に合いそう" );
  CERR( "  ならばクエリ逆読みのUnionFind" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "- 辺の一時的削除更新＋連結成分取得でO(V+E+Q)が間に合いそうならば" );
  CERR( "  強連結成分分解＋トポロジカルソート＋出次数0の非終端頂点削除＋" );
  CERR( "  入出次数1纏め上げや、lowlink" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Acyclic\\StrongConnectedComponent\\HamiltonWalk" );
  CERR( "- 特定の辺を含む最小全域森取得でO((V+Q)log V + E log E)が間に合いそうならば" );
  CERR( "  全体に対する最小全域森をクラスカル法で前計算し重み付きLCAによる" );
  CERR( "  最大コスト辺計算" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest\\Kruscal" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Tree\\Weighted" );
  CERR( "- 辺集合の彩色を変えた最小全域森取得でO(V + E log E + Qα(V))が間に合いそう" );
  CERR( "  ならば全体に対する辺のソートを前計算しクラスカル法の反復" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest\\Kruscal" );
  CERR( "- クエリごとに１つの頂点を始点または終点とする辺全てにわたる更新か取得が" );
  CERR( "  必要な場合、次数√E以下の点は愚直に処理しそうでない点のみ管理する高速化" );
  CERR( "を検討しましょう。" );  
}

AC( QueryCounting )
{
  ASK_NUMBER(
             "部分列の数え上げ" ,
             "辞書順最大／最小の部分列の長さ計算" ,
             "最小元である成分数の数え上げ" ,
             "多重集合の要素の数え上げ" ,
             "操作回数の数え上げ"
             );
  if( num == num_temp++ ){
    CERR( "配列に関する条件Pが与えられているとします。" );
    CERR( "配列Aの区間[l,r]の部分列BであってPを満たすものの数え上げは、" );
    CERR( "関数P?1:0の総和計算に帰着されます。" );
    CERR( "" );
    CALL_AC( QuerySubsequenceSum );
  } else if( num == num_temp++ ){
    CERR( "区間の片端を最大／最小成分の位置に置き換える区間縮小操作回数" );
    CERR( "に他なりません。" );
    CALL_AC( QueryCountingShrinkingInterval );
  } else if( num == num_temp++ ){
    CERR( "(最小値,その個数)を管理する可換モノイドで区間取得をし、" );
    CERR( "最小値が最小元であれば個数部分、そうでなければ0を返しましょう。" );
    CALL_AC( QueryArrayMagmaMonoid );
  } else if( num == num_temp++ ){
    CERR( "配列を多重集合へ送る写像fが与えられているとします。" );
    CERR( "区間I[q] subset [0,N)がクエリごとに与えられ、長さNの配列Aの" );
    CERR( "区間I[q]のfによる像S[q]の要素数C[q]を求める問題を考えます。" );
    CERR( "各i in [0,N)ごとにi in S[q]を満たすq全体の集合T[i]を求め、" );
    CERR( "各q in T[i]に対しanswer[q]に1を加算することで計算を検討しましょう。" );
    ASK_YES_NO( "区間の分割に関するfの再帰構造がデータ構造で処理できそうですか？" );
    if( reply == "y" ){
      CALL_AC( QueryArray );
    }
  } else if( num == num_temp++ ){
    CERR( "- 操作回数が区間２つに分けた時に各区間の操作回数から" );
    CERR( "  復元できるならば、操作回数を管理するモノイドで区間取得" );
    CERR( "- 操作回数が端点の追加／削除で簡単に差分計算できるならば、" );
    CERR( "  Moのアルゴリズム" );
    CERR( "- 操作回数が何らかの明示式で表せるならば、その明次式を" );
    CERR( "  データ構造などで高速に計算" );
    ASK_YES_NO( "区間の片端を最大／最小成分の位置に置き換える区間縮小操作ですか？" );
    if( reply == "y" ){
      CALL_AC( QueryCountingShrinkingInterval );
    }
  }
}

AC( QueryCountingShrinkingInterval )
{
  CERR( "- 置き換えない側の端点でクエリソートしてスライド最大／最小化の" );
  CERR( "  要領で暫定的な最大／最小成分の位置の列を管理しその像をBITで" );
  CERR( "  管理して答えである区間要素数を区間取得で計算" );
  CERR( "- 位置の置き換えを写像とみなし、写像の反復でもう片端に到達する" );
  CERR( "  回数をダブリングで計算" );
  CERR( "を検討しましょう。" );
}

AC( QuerySubsequenceSum )
{
  CERR( "配列を受け取る関数fが与えられているとします。" );
  CERR( "配列Aの区間[l,r]の部分列Bをわたるf(B)の総和を考えます。" );
  CERR( "- まずBを２つの区間に分割してfを2変数関数に翻訳することでfから新たな関数を" );
  CERR( "  得ることを再帰的に繰り返します。" );
  CERR( "- 次にこうして得られた各関数ごとに、" );
  CERR( "  「dp[i] = 第i成分のみからなる区間に対する関数の値」" );
  CERR( "  を考えます。" );
  CERR( "- 最後に、関数の再帰的翻訳を遡って区間のマージに対応する演算を定義し、" );
  CERR( "  データ構造に格納します。" );
  CALL_AC( QueryArray );
}
  
AC( QueryString )
{
  CERR( "文字列の一点更新（一文字更新）／結合／比較はローリングハッシュ" );
  CERR( "\\Utility\\String\\RollingHash" );
  CERR( "でコード化し、追加で更新クエリ／取得クエリを" );
  CERR( "- 左端からの連続部分文字列も管理する場合の一点更新は文字列の累積コードを" );
  CERR( "  区間加算BITに乗せて終切片加算と始切片和取得（O(log N)/O(log N)）で処理" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\BIT\\IntervalAdd" );
  CERR( "- 連続部分文字列も管理する場合、" );
  CERR( "  - ハッシュと公比の冪乗は可換群" );
  CERR( "  - コードは非可換群" );
  CERR( "  を用いることに注意して" );
  CERR( "  - 一点更新のみが必要ならば" );
  CERR( "    - 文字列の各文字のハッシュと公比の冪乗の積を" );
  CERR( "      - BITに乗せて一点更新と区間和取得（O(log N)/O(log N)）" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\BIT" );
  CERR( "      - セグメント木に乗せて一点更新と区間和取得（O(log N)/O(log N)）" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SegmentTree" );
  CERR( "      - 平方分割に乗せて一点更新と区間和取得（O(1)/O(N^{1/2})）" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition" );
  CERR( "      で処理" );
  CERR( "    - 文字列の各文字のコードを" );
  CERR( "      - セグメント木に乗せて一点更新と区間積取得（O(log N)/O(log N)）" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SegmentTree" );
  CERR( "      - モノイド平方分割に乗せて一点更新と区間積取得（O(1)/O(N^{1/2})）" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Monoid" );
  CERR( "      で処理" );
  CERR( "  - 区間代入更新も必要ならば文字列の各文字のコードを" );
  CERR( "    - 遅延セグメント木に乗せて区間代入更新と区間積取得（O(log N)/O(log N)）" );
  CERR( "    - 区間代入モノイド平方分割に乗せて区間代入更新と区間積取得（O(N^{1/2})/O(N^{1/2})）" );
  CERR( "      \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Monoid\\IntervalSet" );
  CERR( "    で処理" );
  CERR( "  - 区間シフト（a->b->c->）更新も必要ならば" );
  CERR( "    - 1の原始26乗根を持つ法でローリングハッシュ" );
  CERR( "      \\Utility\\String\\RollingHash\\Shift\\Bimodule" );
  CERR( "    - 比較したい２つの文字列の各成分のずれ情報を1<<26未満の非負整数のbit積で管理" );
  CERR( "    をした上で区間作用と区間積取得" );
  CERR( "    \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\LazyEvaluation" );
  CERR( "    で処理" );
  CERR( "を検討しましょう。" );
}

AC( QueryTwoAryFunction )
{
  CERR( "区間取得は" );
  CERR( "- 始切片取得の差で表す" );
  CERR( "- 中間で分割してマージ" );
  CERR( "に翻訳しましょう。" );
  CERR( "- 可換群に値を持つ配列の範囲取得は累積積" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProduct" );
  CERR( "- 片側差分がO(1)で計算できる2変数関数の計算はMoのアルゴリズム" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
  CERR( "を検討しましょう。それ以外にも範囲更新可能なデータ構造も検討しましょう。" );
}

AC( QueryTimeSeriesChange )
{
  CERR( "時系列更新が配列の一点更新で与えられる場合は更新イベントがO(Q)個しかないので、" );
  CERR( "各成分ごとに変化時刻で区切った区間をセグメント木の要領で管理することで" );
  CERR( "O(Q)個のノードに合計O((N+Q)log Q)個の区間を分割統治することが可能です。" );
  ASK_NUMBER(
	     "maxによる時系列更新" ,
	     "加算による時系列更新" ,
	     "差の絶対値による時系列更新"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryTimeSeriesChangeMax );
  } else if( num == num_temp++ ){
    CALL_AC( QueryTimeSeriesChangeAddition );
  } else {
    CALL_AC( QueryTimeSeriesChangeDifference );
  }
}

AC( QueryTimeSeriesChangeMax )
{
  ASK_NUMBER(
	     "全体max更新／区間和取得" ,
	     "範囲max更新／一点取得"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryTimeSeriesTotalChangeMax );
  } else {
    CALL_AC( QueryTimeSeriesRangeChangeMax );
  }
}

AC( QueryTimeSeriesTotalChangeMax )
{
  CERR( "全体max更新クエリと区間和取得クエリを時系列順に並べ番号を振ります。" );
  CERR( "これにより配列の特定時刻での区間和を求める問題に帰着され、" );
  CERR( "合計O((N + Q)log N + Q log Q)で処理できます。" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\BIT\\TimeSeriesSetMax" );
}

AC( QueryTimeSeriesRangeChangeMax )
{
  CERR( "時刻tにおける第i成分をA[t][i]と置きます。" );
  CERR( "A[-][i]が単調増加することに注目してxがA[t][i]>=xを満たす条件を決定し、" );
  CERR( "そのようなxの最大値を明示式で書き下しましょう。" );
  CERR( "" );
  CERR( "A[t][i]の明示式にmaxが現れる場合は場合分けでmaxを外し、" );
  CERR( "それぞれの場合の値を各種データ構造で処理しましょう。" );
}

AC( QueryTimeSeriesChangeAddition )
{
  CERR( "各成分を時刻の関数とみなし、それぞれのグラフを考えます。" );
  CERR( "- グラフが合計O(N)個の単純なパーツに分かれるならば、" );
  CERR( "  - 各パーツでの変化量の累積値を階差数列や累積和やBITで計算" );
  CERR( "    \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence" );
  CERR( "    \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProd" );
  CERR( "    \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "  - 各パーツでの変化量の累積値をイベントソートで計算" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\TimeSeriesAdd" );
  CERR( "- グラフが合計O(Q)個の曲線と傾き0の部分に分かれ曲線の両端s,tでの値の差が" );
  CERR( "  成分に依存しない関数fを用いてf(t)-f(s)で表せるならば、fの前計算" );
  CERR( "  参考：https://yukicoder.me/problems/no/2462/editorial" );
  CERR( "を検討しましょう。" );
}

AC( QueryTimeSeriesChangeDifference )
{
  CERR( "時刻tにおける第i成分が|A[i]-t|で与えられるとします。" );
  CERR( "BITをAと(-1)_qで初期化したものをBとCと置きます。" );
  CERR( "(A[i],i)と(t[q],q)を優先度付きキューで管理して、" );
  CERR( "(A[i],i)のイベントではB[i]とC[i]を-1倍に置き換えることで更新し、" );
  CERR( "(t[q],q)のイベントではB[i]+C[i]*tの区間和をq個目のクエリへの回答とする、" );
  CERR( "というイベントソートで処理しましょう。" );
}

AC( Simulation )
{
  CALL_AC( SimulateOperation );
  ASK_YES_NO( "操作回数の計算問題ですか？" );
  if( reply == "y" ){
    CALL_AC( ReducingOperation );
    CALL_AC( CountingOperation );
  }
}

AC( SimulateOperation )
{
  CERR( "まずは愚直なシミュレーションで間に合うか否かを判定し、" );
  CERR( "間に合うならばそのまま実装しましょう。間に合わないならば、" );
  CERR( "- 操作／遷移の纏め上げによる高速化" );
  CERR( "- 序盤+周期性+最終ループ（途中までの可能性があるので最大１周期分見る）" );
  CERR( "- 最終結果に影響するイベントのみを管理" );
  CERR( "  - イベントを重複して解決するならば座標圧縮" );
  CERR( "  - イベントを重複して解決しないならばsetやmapで管理して" );
  CERR( "    イベント処理時に削除" );
  CERR( "- 優先度付きキューなどによるイベントソート" );
  CERR( "  - グリッド内のO(Q)個の縱線と横線の和集合の要素数は、x軸を小さい方から" );
  CERR( "    走査してx軸方向の線分の本数をイベントソートで管理、y軸方向の和集合を" );
  CERR( "    区間代入更新で管理" );
  CERR( "  - 特にグリッド上の経路は線分の集まりとみなして処理可能" );
  CERR( "- イベント群を区間更新クエリに翻訳して双対セグメント木などによる高速化" );
  CERR( "- イベント群をモノイドに翻訳して繰り返し二乗法などによる高速化" );
  CERR( "  - x -> max(bound,x+A_i)の遷移はx -> x+A_iの遷移との差を" );
  CERR( "    累積和の累積maxに翻訳" );
  CERR( "- 操作回数の計算は、何らかの数値に単調性があれば二分探索" );
  CERR( "を検討しましょう。" );
}

AC( QuerySet )
{
  ASK_NUMBER(
             "集合の一点更新（一要素更新／対称差）／比較" ,
             "集合の一点更新（一要素更新／対称差）／帰属判定" ,
             "集合の範囲更新／範囲取得" ,
             "配列の区間の像取得"
             );
  if( num == num_temp++ ){
    CERR( "ゾブリストハッシュ" );
    CERR( "\\Utility\\Set\\ZobristHash" );
    CERR( "を検討しましょう。さらに集合の範囲更新が必要な場合は" );
    CERR( "- 固定要素の有無の反転による一点更新" );
    CERR( "- 対称差" );
    CERR( "ともに加算更新に対応するデータ構造との併用を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "bool値配列もsetも制約に合わずunordered_setの定数倍が厳しい場合、" );
    CERR( "ハッシュの中央の数桁ごとに要素を管理して線形探索をしましょう。" );
    CERR( "\\Utility\\Set\\LinearSearch" );
  } else if( num == num_temp++ ){
    CERR( "集合は{0,1}値配列、多重集合は非負整数値配列に翻訳し、" );
    CERR( "BITなどのデータ構造で処理しましょう。" );
    CERR( "\\Mathematics\\SetTheory\\Line\\Bounded" );
    CERR( "昇順にmod Mでi番目の要素のみを集めた総和を求める際は" );
    CERR( "{mod Mで0番目の要素の総和,...,mod MでM-1番目の要素の総和,要素数}" );
    CERR( "を管理する非可換群に対応するデータ構造との併用を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "区間の像をsetやデータ構造で管理するMoのアルゴリズムを検討しましょう。" );
    CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
    ASK_NUMBER(
               "配列の始切片と区間逆像（ファイバー）の共通部分の最大／最小値取得" ,
               "配列の区間と区間逆像（ファイバー）の共通部分の非空性判定" ,
               "配列の区間の像と区間の包含判定" ,
               "配列の区間におけるmex取得"
               );
    if( num == num_temp++ ){
      CERR( "配列Aの始切片[0,R]と区間[l,r]の逆像の共通部分の最大値取得を考えます。" );
      CERR( "最小値は-1倍で最大値に帰着させます。Rに関してクエリをソートし" );
      CERR( "Aの区間[0,R]の像を{0,1}値でなくファイバーの最大値（ファイバーが空なら-1）" );
      CERR( "により配列Bで管理し、Bの区間[l,r]における最大値を求めると良いです。" );
      CERR( "- 一点最大値更新" );
      CERR( "- 区間最大値取得（一点のファイバーなら一点取得）" );
      CERR( "の可能なデータ構造でBを管理しましょう。" );
      CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
    } else if( num == num_temp++ ){
      CERR( "配列Aの区間[L,R]の像imA[L,R]と区間[l,r]の包含判定を考えます。" );
      ASK_NUMBER(
                 "imA[L,R]が[l,r]に含まれるか否かの判定" ,
                 "imA[L,R]が[l,r]を含むか否かの判定" ,
                 );
      if( num == num_temp++ ){
        CERR( "Aの区間最大値がr以下かつ区間最小値がl以上か否かを判定すれば良いです。" );
        CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
      } else if( num == num_temp++ ){
        CERR( "Rに関してクエリをソートしAの区間[0,R]の像を{0,1}値でなく" );
        CERR( "ファイバーの最大値（ファイバーが空なら-1）により配列Bで管理し、" );
        CERR( "Bの区間[l,r]における最小値がL以上か否かを判定すると良いです。" );
        CERR( "- 一点代入更新" );
        CERR( "- 区間最小値取得（一点のファイバーなら一点取得）" );
        CERR( "の可能なデータ構造でBを管理しましょう。" );
        CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SegmentTree" );
        CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid" );
      }
    } else if( num == num_temp++ ){
      CERR( "配列Aの区間[L,R]におけるmex計算は、Rに関してクエリをソートし" );
      CERR( "Aの区間[0,R]の像を{0,1}値でなくファイバーの最大値（ファイバーが空なら-1）" );
      CERR( "により配列Bで管理し、Bの区間[0,y]における最小値がL未満となる最小のyを" );
      CERR( "始切片最小値取得の二分探索などで求めると良いです。" );
      CERR( "- 一点代入更新" );
      CERR( "- 始切片最小値取得" );
      CERR( "の可能なデータ構造でBを管理しましょう。" );
      CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SegmentTree" );
      CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid" );
    }
  }
}

AC( Game )
{
  ASK_NUMBER(
	     "勝敗を決める2人ゲーム" ,
	     "最終局面での不変量の最大化と最小化を先行と後行が目指す2人ゲーム"
	     );
  if( num == num_temp++ ){
    CALL_AC( DecisionGame );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationGame );
  }
}

AC( Decision )
{
  CERR( "場合分けの複雑な問題は証明の概略をコメントしないとバグを倦めやすいです。" );
  CERR( "なるべくコメントを書くようにしましょう。" );
  ASK_NUMBER(
	     "必勝性問題" ,
	     "連結性問題" ,
	     "到達可能性問題" ,
	     "描画可能性問題" ,
	     "存在判定問題" ,
	     "操作／選択可能性問題" ,
	     "充足可能性問題" ,
	     "一致／同型性判定問題" ,
	     "表示可能性問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( DecisionGame );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionConnectedness );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionAccessibility );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionDrawability );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionExistence );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionChoosability );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionSatisfiability );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionCoincidence );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  }
  ASK_YES_NO( "何らかの値が閾値以上／以下という条件下で選択の可否を判定する問題ですか？" );
  if( reply == "y" ){
    CERR( "可能な選択中でのその値の最大値／最小値を求め、閾値と比較しましょう。" );
    CALL_AC( Maximisation );
  }
}

AC( DecisionGame )
{
  CERR( "各局面の合法手が誰の手番かに依存しない2人ゲームにおいては、" );
  CERR( "プレイヤーAが着手mを行うと必敗となることが分かっているならば、" );
  CERR( "別のプレイヤーBが着手mを避け続けることでAの必敗となることがあります。" );
  ASK_NUMBER(
	     "操作の継続を目指すゲーム" ,
	     "最終局面での不変量の偶奇を指定するゲーム" ,
	     "最終局面での不変量が与えられた定数以上か否かを競うゲーム" ,
	     "得点の大小を競うゲーム"
	     );
  if( num == num_temp++ ){
    CALL_AC( DecisionContinuingGame );
    CALL_AC( DecisionContinuingGameCheck );
  } else if( num == num_temp++ ){
    CERR( "dp[t] = 初期状態tから確実に最終局面での不変量の値にできる数値の全体集合" );
    CERR( "と定めてtに関する動的計画法を検討し、必要ならばその実験結果から" );
    CERR( "規則を見付けたりデータ構造高速化を行いましょう。" );
    CERR( "\\Mathematics\\Game" );
    CALL_AC( DecisionContinuingGameCheck );
  } else if( num == num_temp++ ){
    CERR( "最終局面での不変量の最大化と最小化を目指すゲームに置き換え、" );
    CERR( "双方が最善を尽くした場合の不変量を求めましょう。" );
    CALL_AC( MaximisationGame );
  } else if( num == num_temp++ ){
    ASK_YES_NO( "操作回数が少なく勝敗がつきそうですか？" );
    if( reply == "y" ){
      CERR( "局面の対称性などに注目して同値な局面を同一視し、" );
      CERR( "それぞれについてしらみ潰しに勝敗を考察してみましょう。" );
    } else {
      CERR( "２プレイヤーの得点差を１つの不変量とみなし、その最大化を行って" );
      CERR( "正負を判定しましょう。" );
      CALL_AC( MaximisationGame );
    }
  }
}

AC( DecisionContinuingGame )
{
  ASK_YES_NO( "先手しか可能でない遷移であって他のどの遷移へも経由できるものがありますか？" );
  if( reply == "y" ){
    CERR( "strategy-stealing argumentで先手必勝判定をしましょう。" );
    CERR( "https://en.wikipedia.org/wiki/Strategy-stealing_argument" );
  }
  ASK_YES_NO( "入力の個数（長さ）は一定ですか？" );
  if( reply == "y" ){
    CERR( "まず愚直解を動的計画法で書いて実験し、勝敗の規則を見付けましょう。" );
    CERR( "デバッグモードで勝敗を計算する際は実験の出力と混ざらないように" );
    CERR( "勝敗を配列に格納してから配列を出力しましょう。" );
    CERR( "" );
    CERR( "規則性が見付からない時は、" );
    CERR( "- 連続して選択できない操作は複数ターンまとめて処理することで" );
    CERR( "  変数の少ない動的計画法に翻訳" );
    CERR( "- 愚直解またはその少変数化における動的計画法のデータ構造高速化" );
    CERR( "- 必勝状態に対応する変数列のOEIS検索やサンプル解析" );
    CERR( "を検討しましょう。" );
  } else {
    CERR( "まずゲームをなるべく簡単な設定に同値変形しましょう。" );
    ASK_YES_NO( "文字列／数列の操作をするゲームですか？" );
    if( reply == "y" ){
      CERR( "文字列は文字を数に変換して数列に置き換えます。" );
      CALL_AC( InterpretingSequenceOperation );
      ASK_YES_NO( "1成分を更新したり末尾追加したりするだけですか？" );
      if( reply == "y" ){
        CERR( "1成分ごとのゲーム和に分解しましょう。" );
      }
    }
  }
  CERR( "ゲームの和に分解できるならばグランディ数を計算、できないならば必勝状態判定" );
  CERR( "をする方針で考察します。" );
  ASK_YES_NO( "状態数や遷移回数上限が10^6程度ですか？" );
  if( reply == "y" ){
    CERR( "グランディ数や必勝状態判定は再帰で計算しましょう" );
  } else {
    ASK_YES_NO( "状態数が少ない場合は状態遷移の全探策が自動化できそうですか？" );
    if( reply == "y" ){
      CERR( "整礎構造を探して順序数の小さい順に実験をし、" );
      CERR( "OEISを用いてグランディ数や必勝状態判定を推測しましょう。" );
      CERR( "\\Mathematics\\Game" );
      CERR( "https://oeis.org/?language=japanese" );
    } else {
      CERR( "手計算での実験だと考察漏れが生じやすいのでグランディ数や必勝状態判定を" );
      CERR( "以外の考察を優先しましょう。" );
    }
  }
  CERR( "良い不変量を探し、不変量を変えないような応酬が可能な" );
  CERR( "操作を無視することで不変量の推移ゲームに帰着させましょう。" );
  ASK_NUMBER(
             "状態がモノイドをなし状態に値を加算するゲーム" ,
             "状態が無向グラフをなし未踏地に移動するゲーム" ,
             "その他のゲーム"
             );
  if( num == num_temp++ ){
    CERR( "先手が何を選んでも続く後手の選択次第で２手の加算値総和を一定値Bの倍数に" );
    CERR( "保てるならば、mod Bでの値の非零性を不変量と見るミラー戦略" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "グラフのタイリングであって、各点ごとにそこから到達可能な同タイル内の点が" );
    CERR( "丁度１個であるものを探し、それによる二部マッチングで移動を決定する" );
    CERR( "ミラー戦略を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- ある成分を無視する同値関係" );
    CERR( "- 操作Aが、何らかの不変量を変えない操作Bで応酬できる場合、" );
    CERR( "  Aを無視する（Aでの移動先を同一視する）同値関係" );
    CERR( "などで状態をタイリングをし、各タイルの到達回数の偶奇を不変量として" );
    CERR( "それを維持するミラー戦略を検討しましょう。" );
  }
  ASK_YES_NO( "ゲームの状態に全順序構造があり勝敗が十分長い区間で一定ですか？" );
  if( reply == "y" ){
    CERR( "勝敗で区間を連結成分に分解し、連結成分の計算に帰着させましょう。" );
  }
}

AC( DecisionContinuingGameCheck )
{
  CERR( "実装ミスだけでなく考察ミスもしやすいので、サンプルが通ってもWAとなったら" );
  CERR( "即座に愚直解との比較を試みましょう。" );
}

AC( DecisionConnectedness )
{
  CERR( "- 無向グラフの弧状連結性は幅優先探索やUnionFind" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "- 有向グラフの強連結性は深さ優先探索による強連結成分分解" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Acyclic\\StrongConnectedComponent" );
  CERR( "- 無向グラフの高次ホモロジー計算は実数や適当な法での掃き出し法" );
  CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\Mod" );
  CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\Real" );
  CERR( "を検討しましょう。" );
}

AC( DecisionAccessibility )
{
  CERR( "移動の前後で変化しない値がある場合、その値が等しい点に絞って考えましょう。" );
  CERR( "コストのパリティに制限がある場合は" );
  CERR( "- 往復による±2調整" );
  CERR( "- 奇閉路によるmod 2調整" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\ShortestCycle\\Odd" );
  CERR( "を検討しましょう。" );
  ASK_NUMBER(
	     "矩形領域の到達可能性（迷路）問題" ,
	     "グラフ上の到達可能性問題" ,
	     "全頂点訪問可能性問題"
	     );
  if( num == num_temp++ ){
    CERR( "迷路の攻略可能性は" );
    CERR( "- スタートとゴールが同一の弧状連結成分に属すこと" );
    CERR( "- スタートとゴールを分断する壁のパスの非存在性" );
    CERR( "などに翻訳しグラフ上の最小コスト移動問題に帰着させましょう。" );
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    ASK_YES_NO( "辺の更新を伴いますか？" );
    if( reply == "y" ){
      CALL_AC( QueryGraph );
    } else {
      ASK_NUMBER(
                 "歩数固定の歩道での到達可能性" ,
                 "歩数固定の経路での到達可能性" ,
                 "一般の歩道での到達可能性" ,
                 );
      if( num == num_temp++ ){
        CERR( "K歩で到達可能か否かを考えます。" );
        CERR( "dp[i][k] = 「k歩で頂点iに到達可能か否か」" );
        CERR( "を管理するkに関する動的計画法O(|E|K)を検討しましょう。" );
      } else if( num == num_temp++ ){
        CERR( "K歩で到達可能か否かを考えます。" );
        CERR( "dp[S][i] = 「これまで通った頂点集合がSで頂点iに到達可能か否か」" );
        CERR( "を管理するSに関するbitDP O(|V|^2 2^{|V|})を検討しましょう。" );
      } else if( num == num_temp++ ){
        CERR( "グラフ上の最小コスト移動問題に帰着させましょう。" );
        CALL_AC( MinimisationMovingCost );
      }
    }
  } else if( num == num_temp++ ){
    CERR( "移動の前後で変化しない値がある場合、その値が等しい点に絞って考えましょう。" );
    CERR( "- 再来訪を許容しないならば、" );
    CERR( "  - 非輪状有向グラフでかつO(V+E)が間に合いそうならば、" );
    CERR( "    トポロジカルソートして始点が先頭にあるかとソート順に遷移可能かで判定" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\Acyclic\\HamiltonPath" );
    CERR( "  - 領域と移動に対称性があるならば、タイリングと二部マッチングによる反復戦略" );
    CERR( "  - O(V^2 2^V)が間に合いそうならば、ヘルドカープ法" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\HeldKarp" );
    CERR( "- 再来訪を許容しO(V+E)が間に合いそうならば、強連結成分分解して" );
    CERR( "  非輪状有向グラフで再来訪を許容しない場合に帰着" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Acyclic\\StrongConnectedComponent\\HamiltonWalk" );
    CERR( "を検討しましょう。" );
  }
  CERR( "" );
}

AC( DecisionDrawability )
{
  CERR( "まずは描画領域内にどのように図形を置くかを決定しましょう。" );
  ASK_YES_NO( "図形を置く際に重なりを許しますか？" );
  if( reply == "y" ){
    ASK_NUMBER(
	       "平行移動のみを除いて単一の図形を置く問題" ,
	       "平行移動とサイズ変更のみを除いて単一の図形を置く問題" ,
	       "複数種類の同一サイズの図形を許して置く問題"
	       );
    if( num == num_temp++ ){
      CALL_AC( DecisionDrawabilityUnique );
    } else if( num == num_temp++ ){
      CALL_AC( DecisionDrawabilityExtension );
    } else if( num == num_temp++ ){
      CALL_AC( DecisionDrawabilitySameSizeOverdrawn );
    }
  } else {
    CALL_AC( DecisionDrawabilitySameSizeUnoverdrawn );
  }
}

AC( DecisionDrawabilityUnique )
{
  CERR( "図形を必要ならば回転させた上で、図形をいくつかの矩形領域の和集合に分解し" );
  CERR( "描画領域内に図形を置けるか否かを図形の位置ごとに２次元累積和や" );
  CERR( "２次元高階階差数列などで判定しましょう。" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\CumulativeProduct\\TwoDimensional" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\DifferenceSequence\\TwoDimensional" );
  CERR( "" );
  CALL_AC( DecisionImageCoincidence );
}

AC( DecisionDrawabilityExtension )
{
  CERR( "描画領域内に図形を置けるサイズの最大値を図形の位置ごとに尺取り法などで" );
  CERR( "前計算し、最大サイズで置くことを考えましょう。" );
  CERR( "" );
  CALL_AC( DecisionImageCoincidence );
}

AC( DecisionDrawabilitySameSizeOverdrawn )
{
  CERR( "正整数Bと描画領域の同値関係であって以下の2条件を満たすものを探しましょう。" );
  CERR( "- どのように図形を置いてもその図形がmod Bで等サイズの図形に分割される。" );
  CERR( "- 商の配色ベクトルmod Bを管理することで得られる必要条件が十分条件でもある。" );
}

AC( DecisionDrawabilitySameSizeUnoverdrawn )
{
  CERR( "可換モノイドGと描画領域の商集合Xとモノイド準同型f:N^X->Gであって" );
  CERR( "どのように図形を置いてもその図形の商の濃度ベクトルのfでの値が" );
  CERR( "一定値cであるものを探しましょう。" );
  CERR( "するとXの濃度ベクトルのfでの値Cが(図形を置く個数)cで表せることが" );
  CERR( "必要条件となります。例えば" );
  CERR( "- Gが群かつC=0かつ(図形を置ける個数)がcの位数の倍数になりえない。" );
  CERR( "- GがNかつ(図形を置ける個数の最大値)cがC未満である。" );
  CERR( "- GがNかつ(図形を置ける個数の最小値)cがCより大きい。" );
  CERR( "などの場合はこの必要条件が成り立たないので塗り分け不可能です。" );
}

AC( DecisionImageCoincidence )
{
  CERR( "描画領域内にどのように図形を置くかを決めた後は２次元階差数列などで" );
  CERR( "実際に描画をし、描画したい図形と一致するかを判定しましょう。" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\DifferenceSequence\\TwoDimensional" );
}

AC( DecisionExistence )
{
  ASK_NUMBER(
	     "数の方程式の解の存在" ,
	     "F_2上の方程式の解の存在" ,
	     "単純な条件を満たす数や配列や文字列の存在" ,
	     "単純な条件を満たす行列の存在" ,
	     "動く範囲の狭い変数の組み合わせで表せる概念の存在" ,
	     "経路の存在" ,
	     "描画方法の存在" ,
	     "配列や文字列の成分の書き換え方法の存在" ,
	     "数やベクトルの表示方法の存在" ,
	     "集合の分割方法の存在"
	     );
  if( num == num_temp++ ){
    CALL_AC( Solving );
    CERR( "" );
    CERR( "方程式の数が足りない代わりに変域に制限がある場合、確定しない変数xを用いて" );
    CERR( "他の変数を表し、各方程式をxの不等式に翻訳して変域の非空判定をしましょう。" );
  } else if( num == num_temp++ ){
    CERR( "bool値の方程式は命題の充足可能性に帰着させましょう。" );
    CALL_AC( DecisionSatisfiability );
  } else if( num == num_temp++ ){
    ASK_YES_NO( "順列の存在判定ですか？" );
    if( reply == "y" ){
      CALL_AC( ConstructionPermutation );
    } else {
      CALL_AC( ConstructionArray );
    }
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionMatrix );
  } else if( num == num_temp++ ){
    CERR( "変数の組み合わせで表して全探策を検討しましょう。" );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionAccessibility );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionDrawability );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionRewritingChoosability );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionPartition );
  }
}

AC( DecisionChoosability )
{
  ASK_NUMBER(
             "遷移により点が目的地に到達できるかの判定" ,
             "選択により配列／文字列が条件を満たせるかの判定"
             );
  if( num == num_temp++ ){
    CALL_AC( DecisionAccessibility );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionRewritingChoosability );
  }
}

AC( DecisionRewritingChoosability )
{
  CERR( "配列／文字列の長さをNとし、" );
  CERR( "dp[i] = i成分目までで打ち切った場合の可否を判定するために必要なデータ" );
  CERR( "を管理する動的計画法を検討しましょう。" );
}

AC( DecisionSatisfiability )
{
  ASK_NUMBER(
	     "命題論理の充足性判定問題" ,
	     "二部グラフの充足可能性問題"
	     );
  if( num == num_temp++ ){
    CERR( "各命題変数の真理値を頂点とするグラフを考え連結性判定に帰着させて" );
    CALL_AC( DecisionConnectedness );
    CERR( "" );
    CERR( "区間処理による真理値更新は各種代数的データ構造を用いましょう。" );
    AC( QueryArray );
  } else if( num == num_temp++ ){
    CERR( "完全二部マッチング判定は最大二部マッチングに帰着させます。" );
    CERR( "" );
    CALL_AC( MaximumBipartite );
  }
}

AC( DecisionCoincidence )
{
  CERR( "- 文字列の一致判定はローリングハッシュ" );
  CERR( "  \\Utility\\String\\RollingHash" );
  CERR( "- 部分文字列との一致判定はZアルゴリズム" );
  CERR( "  \\Utility\\String\\Z-Algorithm" );
  CERR( "- 集合の一致判定はゾブリストハッシュ" );
  CERR( "  \\Utility\\Set\\ZobristHash" );
  CERR( "- 多重集合の一致判定は重複度とpairにして集合の一致判定に帰着" );
  CERR( "- 配列の並び換えによる一致判定は" );
  CERR( "  - 各前処理O(長さlog長さ)が間に合いそうならばソートからの文字列一致判定に帰着" );
  CERR( "  - 各前処理O(長さlog文字種類数)が間に合いそうならば多重集合の一致判定に帰着" );
  CERR( "- グラフの同型性判定は十分多くの不変量（例えば|V|+|E|個くらい）を" );
  CERR( "  GNNで畳み込み" );
  CERR( "  - 同型の構成は畳み込んだ頂点の不変量をソートして最小要素を対応させ、" );
  CERR( "    選んだ頂点の情報を伝播させてループ。お誕生日攻撃を受けるので法を大きく。" );
  CERR( "  - 根付き木の場合は葉から順に畳み込むと根に十分大きな不変量が得られる。" );
  CERR( "    https://hcpc-hokudai.github.io/archive/rupc/2017/rupc2017_F.pdf" );
  CERR( "  - 木の場合は根を全探策して根付き木に帰着。中心など個数の少ない点に根を絞る。" );
  CERR( "を検討しましょう。" );
}

AC( DecisionPresentability )
{
  ASK_NUMBER(
	     "単一の演算による表示可能性（生成部分マグマ問題）" ,
	     "複数の演算による表示可能性（テンパズル問題）"
	     );
  if( num == num_temp++ ){
    CERR( "半群の要素は、加素元からなる極小生成系の要素の和で表せます。" );
    CERR( "- 加素元の和で表すならば、半群が方程式の解空間で与えられる場合には" );
    CERR( "  Qの直和に埋め込めば解の1/nも解であることに着目し、整数の範囲での商を" );
    CERR( "  うまく端数を揃えて解を構成できるかもしれません。" );
    CERR( "- 数を素数の和で表すならば、Klove数列で必要な素数の個数を見積りましょう。" );
    CERR( "  Mathematics\\Arithmetic\\Prime\\KloveSequence\\a.hpp" );
    CERR( "- 数を多角数の和で表すならば、二平方定理などを参考にしましょう。" );
    CERR( "  https://ja.wikipedia.org/wiki/二個の平方数の和#素数についての証明" );
    CERR( "  https://ja.wikipedia.org/wiki/三個の平方数の和#証明" );
    CERR( "  https://ja.wikipedia.org/wiki/四平方定理#ラグランジュの四平方定理の証明" );
    CERR( "  https://ja.wikipedia.org/wiki/多角数定理#証明" );
    CERR( "- 数をXORで表すならば、" );
    CERR( "  - 一般の数を表すならば拡大係数行列の簡約化" );
    CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\BitSet" );
    CERR( "  - 0を非自明なXORで表すならば一次独立性判定" );
    CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\BitSet" );
  } else if( num == num_temp++ ){
    CERR( "- 左結合的に関数／演算を処理する場合は" );
    CERR( "  「第i成分／文字までで打ち切った時に表現できるもの全体の集合dp[i]」" );
    CERR( "  を管理するiに関する動的計画法" );
    CERR( "- 結合順が指定されている場合はBNFを直接用いた再帰で構文解析をして" );
    CERR( "  「第iノードまでで打ち切った時に表現できるもの全体の集合dp[i]」" );
    CERR( "  を管理するiに関する木DP" );
    CERR( "- 関数／演算の適用方法にも選択がある場合は2項を選んで適用させた" );
    CERR( "  結果得られる数／文字列の再帰的な全探策" );
  }
  CERR( "を検討しましょう。" );
  CALL_AC( MinimisationExpression );
}

AC( Construction )
{
  CERR( "- 存在定理に帰着できる問題は構成的証明を実装" );
  CERR( "- 小さいケースで実験できる時は" );
  CERR( "  - 小さいケースでの構築を自然に拡張" );
  CERR( "  - 入力に関して再帰的に構築する方法を探すために、入力制約より一般化したり" );
  CERR( "  （例えば多変数化して）逆に制約を追加したりして考察" );
  CERR( "を検討しましょう。" );
  ASK_NUMBER(
	     "数やベクトルに関する構築" ,
	     "配列や文字列に関する構築" ,
	     "順列に関する構築" ,
	     "行列に関する構築" ,
	     "写像の構築" ,
             "グラフに関する構築" ,
	     "戦略の構築" ,
             "集合に関する構築" ,
             "タイリングの構築" ,
	     "ソースコードの構築"
	     );
  if( num == num_temp++ ){
    CALL_AC( ConstructionNumber );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionArray );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionPermutation );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionMatrix );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionMap );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionGraph );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionStrategy );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionSet );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionTiling );
  } else if( num == num_temp++ ){
    CERR( "正解を出力をするソースコードを提出しましょう。" );
  }
}

AC( ConstructionNumber )
{
  ASK_NUMBER(
	     "数や固定長ベクトルの表示方法の構築" ,
	     "方程式の解の構築" ,
             "位取り記法表示が何らかの性質を持つ数の構築"
             );
  if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  } else if( num == num_temp++ ){
    CALL_AC( Solving );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionDigits );
  }
}

AC( ConstructionDigits )
{
  CERR( "- 構築する桁数が少なければ、候補を絞って全探策" );
  CERR( "- 入力の位取り記法表示Sと関係のある性質であれば、" );
  CERR( "  制約から探索可能な文字列操作を逆算して" );
  CERR( "  - Sに0...0などを挿入" );
  CERR( "  - Sの各桁を固定回数反復" );
  CERR( "  - Sの部分文字列を反復" );
  CERR( "を検討しましょう。" );
}

AC( ConstructionArray )
{
  ASK_NUMBER(
	     "条件を満たす配列や文字列の構築" ,
	     "与えられた配列や文字列の条件を満たす部分列の構築"
             );
  if( num == num_temp++ ){
    CERR( "- １つの配列の構成は、p進法や階差数列への翻訳を検討しましょう。" );
    CERR( "- 何らかの関数値が一致する２つの配列の構成は、鳩の巣原理をもとに" );
    CERR( "  動かすパラメータを設定し、全探策を検討しましょう。" );
  } else {
    CALL_AC( ConstructionPartition );
  }
}

AC( ConstructionPermutation )
{
  ASK_YES_NO( "順列Pの何らかのスコアf(P)が定義される問題ですか？" );
  if( reply == "y" ){
    CERR( "Pが存在する必要十分条件を、f(P)が特定の区間に属すことに翻訳しましょう。" );
    CERR( "- f(P)を決め打ってPの探索" );
    CERR( "  - 焼き鈍し法による最適化" );
    CERR( "    \\Mathematics\\Combinatorial\\SimulatedAnnealing" );
  }
  CERR( "- 互換表示や巡回置換表示の探索" );
  CERR( "- 階乗進法で探索" );
  if( reply == "y" ){
    CERR( "  - f(P)がPの階乗進法に関して単調ならば二分探索" );
  }
  CERR( "- -1して法Nに帰着させ、(x+yi)_iの形に絞って考察" );
  CERR( "- 小さいケースはnext_permutationで愚直" );
  CERR( "  - 実験をしてNがある程度大きい際の存在の必要十分条件が得られたら" );
  CERR( "    それより大きいケースを再帰で小さいNに帰着" );
  if( reply == "y" ){
    CERR( "  - f(P)の動く範囲が狭くかつf(P)=f(Q)を満たすP!=Qを探すならば、" );
    CERR( "    Pの先頭を固定して鳩の巣原理で末尾いくつかを全探策" );
  }
  CERR( "- 端を確定させた時の条件が残りの部分の構築に帰着できそうならば、" );
  CERR( "  端から確定させる再帰" );
  CERR( "  - 順列全体より狭く、毎回端を残っている最大か最小に割り振る制限" );
  if( reply == "y" ){
    CERR( "  - 確定させる値によってf(Pの残り)の属すべき区間がどう変化するかの計算" );
  }
  CERR( "- 順列の残りの候補から要素を選択する際は" );
  CERR( "  - 追加と削除両方行うならば、sorted setやBITによる集合管理" );
  CERR( "    \\Mathematics\\SetTheory\\Line\\Bounded" );
  CERR( "  - 削除のみ行うならば、LinkedVectorで残りをベクトルで管理し、" );
  CERR( "    素集合データ構造で削除を「左に残っているうちの最大元への結合」に翻訳" );
  CERR( "    \\Utility\\Vector\\Linked" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "を検討しましょう。" );
}

AC( ConstructionMatrix )
{
  ASK_YES_NO( "いくつかの成分の和の像が多重集合として固定されている問題ですか？" );
  if( reply == "y" ){
    CERR( "像をソートした数列の階差数列を考え、その成分ごとに行列を範囲更新しましょう。" );
  }
  CERR( "行列の数え上げ問題に帰着させ、復元しましょう。" );
  CALL_AC( CountingMatrix );
}

AC( ConstructionMap )
{
  CERR( "- 単射の構築にはHallの結婚定理" );
  CERR( "  https://ja.wikipedia.org/wiki/ホールの定理" );
  CERR( "- 全単射の構築にはホップクロフトカープ法やカントールベルンシュタインの定理" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\HopcroftKarp" );
  CERR( "  https://ja.wikipedia.org/wiki/ベルンシュタインの定理#証明" );
  CERR( "- 全射の構築には部分集合を制限して全単射の構築の反復" );
  CERR( "を検討しましょう。" );
}

AC( ConstructionGraph )
{
  ASK_NUMBER(
	     "グラフの構築" ,
	     "彩色の構築" ,
	     "グラフ上の操作の構築"
	     );
  if( num == num_temp++ ){
    CALL_AC( ConstructionEdge );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionColouring );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionOperationOnGraph );
  }
}

AC( ConstructionEdge )
{
  CERR( "- 2頂点が非連結なグラフの構築は、2頂点を隔てる壁の構築、例えば" );
  CERR( "  - グリッドなら8方向移動で端を結ぶ壁の構築" );
  CERR( "  - その他のグラフなら1頂点の近傍点を境界とする壁の構築" );
  CERR( "- 木の構築は、" );
  CERR( "  - 直線や二分木やウニなど、シンプルなものに制限した構築" );
  CERR( "  - 二分木なら括弧列やグリッド上の対角線を跨がない経路の構築" );
  CERR( "に帰着させましょう。" );
}

AC( ConstructionColouring )
{
  ASK_YES_NO( "色ごとに分けた部分グラフの性質が指定された問題ですか？" );
  if( reply == "y" ){
    CERR( "グラフの構築に帰着させましょう。グラフの構築は" );
    CALL_AC( ConstructionEdge );
  } else {
    CERR( "- 有向非輪状グラフの場合は、端点から確定" );
    CERR( "  - 特に木の場合は、全体問題と部分問題が同じ問題であることに注目して" );
    CERR( "    再帰的構築" );
    CERR( "- 一般のグラフの場合は、満たすべき条件をスコア付けして貪欲に決めていき、" );
    CERR( "  その後で焼き鈍し法などで最適化するヒューリスティック解法" );
    CERR( "- 条件が羃等モノイド演算で記述できる場合、単位元（演算に影響を与えない）" );
    CERR( "  で初期化をして単位元の個数を管理しながら単位元の書き換え" );
    CERR( "を検討しましょう。" );
  }
}

AC( ConstructionOperationOnGraph )
{
  ASK_NUMBER(
	     "最短経路の構築" ,
	     "最長経路の構築" ,
	     "グリッドやユークリッド空間内での操作の構築"
	     );
  if( num == num_temp++ ){
    CERR( "最短経路探索アルゴリズムで経路復元をしましょう。" );
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CERR( "最長経路探索アルゴリズムで経路復元をしましょう。" );
    CALL_AC( MaximisationMovingDistanceSingleStart );
  } else {
    CERR( "- HWが小さいケースを手作業または全探策で求めて、" );
    CERR( "  一般のHWは小さいケースの反復" );
    CERR( "- 規則的な操作を(mod H,mod W)し、適宜unordered_set<T2<int>>で" );
    CERR( "  重複管理し重複時にはずらす" );
    CERR( "- グリッド上の巡回セールスマン問題に対するヒューリスティック解の構築は" );
    CERR( "  Moのアルゴリズムによるソート" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
    CERR( "を検討しましょう。" );
  }
}

AC( ConstructionStrategy )
{
  ASK_NUMBER(
	     "必勝戦略の構築" ,
	     "最大化戦略の構築"
             );
  if( num == num_temp++ ){
    CALL_AC( DecisionGame );
  } else {
    CALL_AC( ConstructionMaximisation );
  }
}

AC( ConstructionMaximisation )
{
  CERR( "最終的な不変量を最大化するためには、操作の整礎な変形手順であって" );
  CERR( "値を減らさないものを探し、その変形を完全に行って得られる操作のみに" );
  CERR( "絞って考えましょう。その変形によって貪欲な操作が可能であれば" );
  CERR( "貪欲法で解くことが可能です。" );
  CERR( "" );
  CALL_AC( Maximisation );
}

AC( ConstructionSet )
{
  ASK_NUMBER(
	     "与えられた二部グラフの部分集合の構築" ,
	     "与えられた集合の分割方法の構築"
             );
  if( num == num_temp++ ){
    CALL_AC( ConstructionSubset );
  } else {
    CALL_AC( ConstructionPartition );
  }
}

AC( ConstructionSubset )
{
  CERR( "連結二部グラフ(S,T)と、s in SとTの部分集合T0に関する条件P(s,T0)であって" );
  CERR( "- 任意のs in SとTの部分集合T0とd(s,t)=1を満たすt in T0に対し、" );
  CERR( "  P(s,T0)<=>!P(s,T0-{t})である。" );
  CERR( "を満たすものが与えられているとして、" );
  CERR( "- 任意のs in U cap Sに対し、P(s,U cap T)である。" );
  CERR( "を満たすS cup Tの部分集合Uで濃度が補集合以上であるものの構築を考えます。" );
  CERR( "" );
  CERR( "Tを整列させ、各s in Sに対しd(s,t)=1を満たす最大のt in Tをf(s)と置きます。" );
  CERR( "Uを{}で初期化してt in Tの小さい順に" );
  CERR( "- {s in f^{-1}(t)|P(s,U cap T)}" );
  CERR( "- {s in f^{-1}(t)|P(s,(U cap T) cup {t})} cup {t}" );
  CERR( "のうち濃度が小さくない方の各要素をUに追加します。fの逆像はSの排他的被覆を" );
  CERR( "与えるので、最終的なUの濃度は補集合以上になります。" );
}

AC( ConstructionPartition )
{
  CERR( "集合や文字列や配列の分割は写像の一種です。" );
  AC( ConstructionMap );
}

AC( ConstructionTiling )
{
  CERR( "グリッドのタイリングは" );
  CERR( "- 実装の削減" );
  CERR( "  - 転置による場合分けの削減" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Grid\\Tranposition" );
  CERR( "  - 座標１つと向きだけ指定してタイル配置を行う関数の導入" );
  CERR( "  - x軸とy軸の範囲を指定して周期的なタイリングを行う関数の導入" );
  CERR( "- 小さいケースへの帰着" );
  CERR( "  - 短辺と1辺を共有する長方形を構築し、長辺を周期的な縮小" );
  CERR( "  - 縮小不可能な小さい長方形の考察（サンプルに帰着）" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "そしてタイルによる長方形の描画可能性判定を行いましょう。" );
  CALL_AC( DecisionDrawability );
}

AC( Deduction )
{
  CERR( "リアクティブ問題で質問をする際は" );
  CERR( "- 何らかの順序における極大元に触れる聞き方" );
  CERR( "- なるべく多くの数値に依存する情報に触れる聞き方" );
  CERR( "- N^2個の数値に対するO(N)回の質問では対角線に触れる聞き方" );
  CERR( "- 既存のアルゴリズムを分解する聞き方" );
  CERR( "  - 単調関数の最大／最小化問題や零点探索なら二分探索" );
  CERR( "  - 凸関数の最大／最小化問題なら三分探索" );
  CERR( "  - 順序集合の最大／最小要素計算ならトーナメントや勝ち抜き戦" );
  CERR( "を検討しましょう。" );
}


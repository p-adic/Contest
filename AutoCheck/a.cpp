// c:/Users/user/Documents/Programming/Contest/AutoCheck/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

extern int exec_mode;

#include "LibrarySearch/a_Body.hpp"
#include "SampleAnalyser/a_Body.hpp"

#include "../../Utility/StdStream/a_Body.hpp"

void AutoCheck( const bool& use_getline , const bool& sample_check , const string& problem_order )
{
  int num = 0;
  int num_temp = 0;
  string reply{};
  vector<string> problems{};
  int problems_size = 0;
  bool registered_sample = false;
  if( sample_check ){
    ifstream ifs{ "c:/Users/user/Documents/Programming/Contest/AutoCheck/SampleMemoriser/Sample/register_log.txt" };
    string s_curr;
    while( !ifs.eof() ){
      ifs >> s_curr;
      if( s_curr == problem_order ){
        registered_sample = true;
        break;
      }
    }
  }
  ASK_NUMBER(
             "提出用ファイルを実行する。" ,
             sample_check ? registered_sample ? "提出用ファイルが" + problem_order + "問題のサンプルと合うかを確認する。" : "（サンプル登録失敗により選択不可）" : "（サンプル確認モードでないので選択不可）" ,
             "サンプルの合わない提出用ファイルをデバッグする。" ,
             "提出済みファイルをデバッグする。" ,
             "ライブラリーを探索する。" ,
             "サンプルを解析する。" ,
             "愚直解で実験する。" ,
             "提出用ファイルの実行または愚直解との比較を小さいケースで行う。" ,
             "提出用ファイルの実行または愚直解との比較をランダムケースで行う。" ,
             "終了する。"
             );
  exec_mode = num;
  if( num == solve_mode ){
    CERR( "提出用ファイルを実行します。" );
  } else if( num == sample_check_mode ){
    assert( sample_check && registered_sample );
    CERR( "提出用ファイルが" + problem_order + "問題のサンプルと合うかを確認します。" );
  } else if( num == sample_debug_mode ){
    CALL_AC( DebugHintWA );
  } else if( num == submission_debug_mode ){
    CALL_AC( DebugHint );
  } else if( num == library_search_mode ){
    CALL_AC( LibrarySearch );
  } else if( num == sample_analysis_mode ){
    CALL_AC( SampleAnalyser );
  } else if( num == experiment_mode ){
    CERR( "愚直解で実験します。" );
  } else if( num == small_test_mode ){
    CERR( "愚直解と提出用ファイルを入力の小さいテストケースで比較します。" );
  } else if( num == random_test_mode ){
    CERR( "愚直解と提出用ファイルをランダムテストで比較します。" );
  } else if( num == quit_mode ){
    CERR( "終了します。" );
  }
  CERR( "" );
}

AC( DebugHint )
{
  ASK_NUMBER(
	     "WAのデバッグ" ,
	     "REのデバッグ" ,
	     "TLEのデバッグ" ,
	     "MLEのデバッグ" ,
	     "CEのデバッグ"
	     );
  if( num == num_temp++ ){
    CALL_AC( DebugHintWA );
  } else if( num == num_temp++ ){
    CERR( "abort系:" );
    CERR( "- 制約を間違えてassertしていませんか？" );
    CERR( "" );
    CERR( "ローカルでのabort系（提出時はWAなど）:" );
    CERR( "- 配列外参照していませんか？" );
    CERR( "  - 座標圧縮畤に圧縮前の添字操作と圧縮後の添字操作を混同していませんか？" );
    CERR( "  - グラフや座標圧縮の操作で存在しない座標-1の場合分けを忘れていませんか？" );
    CERR( "- オーバーフローしていませんか？" );
    CERR( "" );
    CERR( "Segmentation Fault系:" );
    CERR( "- 手元の環境ではDEXPRで設定した値が小さくなることを忘れていませんか？" );
    CERR( "- 二分探索マクロで探索値が存在しない場合にMAXIMUM+1が返ることを忘れていませんか？" );
    CERR( "- イテレータを範囲外まで--/++していませんか？" );
    CERR( "- 仮想継承した関数をコンストラクタ内で呼び出していませんか？" );
    CERR( "- 複数翻訳単位でデバッグ用と提出用の2種類のクラス定義を行って" );
    CERR( "  メモリサイズが変わりメモリが壊れていませんか？" );
    CERR( "" );
    CERR( "arithmetic exception系:" );
    CERR( "- 0で割っていませんか？" );
    CERR( "" );
    CERR( "Heap block/signal SIGTRAP系:" );
    CERR( "- 動的配列で配列外に代入していませんか？" );
  } else if( num == num_temp++ ){
    CERR( "- マルチテストケースでデータ構造の初期化が反復されていませんか？" );
    CERR( "  - 動的配列への置き換え" );
    CERR( "  - 座標圧縮" );
    CERR( "    \\Mathematics\\SetTheory\\DirectProduct\\CoordinateCompress" );
    CERR( "  を検討しましょう。" );
    CERR( "- whileループで無限ループはありませんか？" );
    CERR( "  - 添字等の更新忘れはありませんか？" );
    CERR( "  - 初期化されていない変数はありませんか？（手元でのみ通る場合）" );
    CERR( "- DEXPR使用時に手元とオンライン環境で実行時間が変わることを失念していませんか？" );
    CERR( "- デバッグ用の処理の消し忘れはありませんか？" );
    CERR( "  - cerrが残っていませんか？" );
    CERR( "  - 実装が空のデバッグ用関数の呼び出しコストを無視していませんか？" );
    CERR( "- 重過ぎる定数倍を考慮し忘れてませんか？" );
    CERR( "  - bool値の処理はbit演算による並列化" );
    CERR( "  - 変数の和や積に上限があるグリッド問題は動的配列" );
    CERR( "  を検討しましょう。" );
    CERR( "- 前計算できる処理を繰り返してませんか？" );
    CERR( "  - 各(i,j)ごとにS_ijを構築する代わりに各iごとにS_iを構築してS_iとS_jで" );
    CERR( "    S_ijをO(1)で構築することを検討しましょう。" );
    CERR( "- multisetのcountを使っていませんか？" );
    CERR( "- リアクティブ問題でflushと改行をし忘れていませんか？" );
    CERR( "- 特殊ジャッジ問題でassertなどに引っ掛かりジャッジの入力待ちになっていませんか？" );
    CERR( "- gccのvariadic arrayのバグの可能性がありませんか？" );
    CERR( "- 畳み込みでgccを使っていませんか？" );
    CERR( "- 構築可能性の判定問題であれば、時間を計測して打ち切りましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- グラフで辺を持ち過ぎていませんか？" );
    CERR( "- （多重）配列でサイズが10^6を大幅に上回ってませんか？" );
    CERR( "  - データ構造は座標圧縮を検討しましょう。" );
    CERR( "  - 動的計画法は初期化忘れに注意して添字のswapやmodを検討しましょう。" );
    CERR( "- 再帰／非再帰の選択を誤っていませんか？" );
    CERR( "  - 再帰でMLEしていますか？" );
    CERR( "    - 関数の引数や局所変数を再帰呼び出しの後に用いる場合それらをメモリ上に" );
    CERR( "      保持し続ける必要があるのでメモリ使用量が膨れ上がります。" );
    CERR( "    - 同再帰深度での呼び出し回数より最大再帰深度が大きい場合は" );
    CERR( "      軽い処理でも非再帰にした方がメモリ節約できるかもしれません。" );
    CERR( "    - 例えばメモリ上に変数を保持しない簡単な処理は再帰深度10^8でも大丈夫です。" );
    CERR( "  - 非再帰でMLEしていますか？" );
    CERR( "    - 変数を逐一構築する軽め再帰でも再帰深度が10^6以下なら大丈夫です。" );
    CERR( "    - 最大再帰深度より同再帰深度での呼び出し回数が大きい場合は" );
    CERR( "      重い処理でも再帰した方がメモリ節約できるかもしれません。" );
    CERR( "    - 例えば毎回10^5オーダーの配列を構築する再帰でも最大再帰深度が10程度なら" );
    CERR( "      再帰した方がメモリ上の変数の個数を10^6オーダーで抑えられます。" );
    CERR( "- 幅／深さ優先探索の選択を誤っていませんか？" );
    CERR( "  - 出次数が大きい場合、幅優先探索ではMLEするかもしれません。" );
    CERR( "  - 出次数が1の頂点が多い場合、深さ優先探索ではMLEするかもしれません。" );
    CERR( "- 実行時計算のシフト演算子が64周期であることを忘れていませんか？" );
    CERR( "  - 例えば1LL<<-1は-2^{63}になります。" );
    CERR( "  - 例えば1024>>65は512になります。" );
    CERR( "  - コンパイル時計算はそうではないようです。" );
    CERR( "- Python使用畤に変数名の重複による型エラーが起きてませんか？" );
    CERR( "  - rangeのRと[L,R)のRの重複は後者に[l,r)を用いて解消しましょう。" );
    CERR( "  - 素数のPと順列のPの重複は後者にAやQを用いて解消しましょう。" );
    CERR( "- Python使用畤に桁数が大きくなり過ぎていませんか？" );
  } else if( num == num_temp++ ){
    CERR( "- 完全型を使っているつもりでinvalid use of incomplete typeが出ている時は" );
    CERR( "  - クラステンプレートのテンプレート引数を間違えていませんか？" );
    CERR( "  - クラステンプレートのテンプレート引数を部分特殊化してメンバ関数を" );
    CERR( "    定義しようとしていませんか？" );
    CERR( "    - 部分特殊化に対しクラスを完全に宣言し直して他のメンバも定義するか" );
    CERR( "      完全特殊化をinline付きで定義しましょう。" );
    CERR( "- multiple definitionが出ている時は" );
    CERR( "  - pragma onceの付け忘れをしていませんか？" );
    CERR( "  - 関数templateの完全特殊化のinlineの付け忘れをしていませんか？" );
    CERR( "- expected primary expressionが出ている時は" );
    CERR( "  - 直前の行でセミコロンを付け忘れていませんか？" );
    CERR( "  - 変数名のメンバアクセスのつもりでクラス名に.を付けていませんか？" );
    CERR( "  - 3項演算子の?:を::や:,に書き間違えていませんか？" );
    CERR( "- オーバーロードされた関数にconst char*[]を引数に渡した時に" );
    CERR( "  no matching functionが出ている時は、const char*[]への特殊化を" );
    CERR( "  工夫しても解決できないのでstringへの特殊化を用意して関数テンプレートに" );
    CERR( "  to_stringを噛ませましょう。" );
  }
  CERR( "" );
  CERR( "提出済みファイルのデバッグは以上です。終了します。" );
}

AC( DebugHintWA )
{
  CERR( "- int型同士の乗法がオーバーフローしていませんか？" );
  CERR( "- operator<<()をint型に適用していませんか？" );
  CERR( "- 実行時計算のシフト演算子が64周期であることを忘れていませんか？" );
  CERR( "  - 例えば1LL<<-1は-2^{63}になります。" );
  CERR( "  - 例えば1024>>65は512になります。" );
  CERR( "  - コンパイル時計算はそうではないようです。" );
  CERR( "- イベント管理にsetを使っていませんか？" );
  CERR( "  - keyに狭義全順序を用いる場合、" );
  CERR( "    - 同一keyの処理を同時に行うならばmapを検討しましょう。" );
  CERR( "    - 同一keyの処理を同時に行わないならばmultisetを検討しましょう。" );
  CERR( "  - keyに狭義全順序の積順序を用いる場合、mapの入れ子を検討しましょう。" );
  CERR( "- 動的計画法においてindexのswapやmodを用いてメモリ削減を行う場合、" );
  CERR( "  各ループの最初にdpテーブルの初期化をし忘れていませんか？" );
  CERR( "- 数え上げや存在判定において、探すべき対象に課されている条件を忘れて" );
  CERR( "  いませんか？" );
  CERR( "  - 三角形を探す代わりに成立条件３つを満たしていない３点を探して" );
  CERR( "    いませんか？" );
  CERR( "  - 要素数Kの部分集合を探す代わりに部分集合全体を探していませんか？" );
  CERR( "- 変数名の衝突した局所変数による秘匿化を受けていませんか？" );
  CERR( "- l^1距離とl^∞距離を間違えていませんか？" );
  CERR( "- 誤差評価をし忘れていませんか？" );
  CERR( "  - 整数型へのキャスト時の切り捨てが適切かを確認しましょう。" );
  CERR( "  - 二分探索等で厳密値を扱う時は代数方程式を解いて誤差を消しましょう。" );
  CERR( "- 番兵などによる例外処理のミスをしていませんか？" );
  CERR( "  - 単なる定数倍高速化を目的とする例外処理は削除して試してみましょう。" );
  CERR( "  - 実装の高速化を目的とする例外処理は削除せず正当性の証明を再確認" );
  CERR( "    しましょう。" );
  CERR( "- 面積計算で格子点の個数と長さを混同していませんか？" );
  CERR( "  - 領域を管理する際は「右下の単位矩形が塗られるか」の情報を各格子点に" );
  CERR( "    乗せましょう。" );
  CERR( "  - 座標圧縮する際は「塗る領域の端点」を±1せずに管理しましょう。" );
  CERR( "- 複雑な処理をmain関数内に書き過ぎていませんか？" );
  CERR( "  - 複数回用いる意味のあるexpressionは変数で置きましょう。" );
  CERR( "  - バグの検証の難しい処理は関数化しましょう。" );
  CERR( "  - 関数化された処理は、そこだけをテストしてみましょう。" );
  CERR( "- inplace処理を行う２項演算で２項が等しい場合を考慮し忘れていませんか？" );
  CERR( "- TruncatedPolynomialをPolynomialにキャストしてm_Nよりm_sizeが大きく" );
  CERR( "  なっていませんか？" );
  CERR( "- マルチテストケースで配列にstaticをつけて値が持ち越されていませんか？" );
  CERR( "- cLay使用畤にsetmod以前に10^9+7より大きい値を代入していませんか？" );
  CERR( "  #define MD 998244353 などを用いましょう。" );
  CERR( "" );
  CERR( "原因に心当たりがない場合はランダムテストを検討しましょう。" );
  CERR( "ランダムテストで引っ掛らない場合は" );
  CERR( "- 大きな入力値でのみ起こるバグ" );
  CERR( "  - 型の指定ミス" );
  CERR( "  - 64bit型のオーバーフロー" );
  CERR( "- メモリの破壊によって起こる環境依存のバグ" );
  CERR( "  - []やsortの範囲指定ミス" );
  CERR( "  - 二重配列で[i][j]と[j][i]の書き間違い" );
  CERR( "を疑いましょう。" );
}


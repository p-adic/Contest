// c:/Users/user/Documents/Programming/Contest/ProblemCreation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "ExecuteSolution/a_Body.hpp"
#include "GenerateSamples/a_Body.hpp"
#include "RearrangeSamples/a_Body.hpp"
#include "WriteInSamples/a_Body.hpp"

// "../../Utility/StdStream/a_Body.hpp"��include�����B
#include "../../Mathematics/Utility/BinarySearch/a_Body.hpp"
#include "../../Mathematics/Utility/TwoPointerApproach/a_Body.hpp"

// �f�o�b�O�p
inline void AlertAbort( int n ) { CERR( "abort�֐����Ă΂�܂����Bassert�}�N���̃��b�Z�[�W���o�͂���Ă��Ȃ��ꍇ�̓I�[�o�[�t���[�̗L�����m�F�����Ă��������B" ); }
void AutoCheck( int& exec_mode , const bool& use_getline );
inline void Solve();
inline void Experiment();
inline void SmallTest();
inline void RandomTest();
inline void BreakPoint( const int& LINE ) {}

#ifdef USE_GETLINE
  CEXPR( bool , use_getline , true );
#else
  CEXPR( bool , use_getline , false );
#endif

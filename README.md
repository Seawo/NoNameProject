## BOSS ( CSW부분 )
<https://www.youtube.com/watch?v=ZlltAufpLec&list=PLI4ALOxREG_WXlYnrLniYcXgxgPxHiFxq&index=4>

### Struct
- Enemy 구조
  - State 관리
  - AttackPattern 관리
  - Montage 재생 하면서 재생 기능 활성화
![스크린샷 2024-12-11 115537](https://github.com/user-attachments/assets/105bbdf2-31ed-47f2-8100-95dc53501f7a)

### Function
![공격패턴1](https://github.com/user-attachments/assets/13b0db21-b878-4db4-a0fe-7b3a517c8f8d)
![공격패턴2](https://github.com/user-attachments/assets/a70ab04a-7b36-4221-90da-ed2f36f3f0db)
- 데미지가 들어가는 Circle을 생성
이후 추가 번개가 떨어지면서 더 큰 데미지가 가해진다
- 서버에서 위치와 스폰 할 Actor계산후 -> 클라이언트 ( Pos[] , Actor )
- Actor ( 떨어지는 번개의 나이가라를 다르게 주면서 일정한 번개가 모양이 아닌 다양한 번개가 떨어지면서 눈의 즐거움을 줌 ) 


![공격패턴3](https://github.com/user-attachments/assets/0dd0cf1d-58b3-43ed-ad84-40a8d8d9b881)
- 회오리가 등장하면서
가장 가까운 적 or 가장 멀리 있는 적을 타겟팅 하는 랜덤 회오리가 등장 한다
-  서버에서 위치와 스폰 할 Actor 계산후 -> 클라이언트 ( Pos[] , Actor ) 
- Actor ( 가장 가까운 적을 공격하는 엑터, 가장 먼 적을 공격하는 엑터, 랜덤으로 아무나 공격하는 엑터 )가 존재

![Sturn](https://github.com/user-attachments/assets/178e183e-88d1-46ff-9c6b-d8341a256c0d)
- 일정 확률로 나오는 치명타를 입으면 스턴 상태로 돌입하게 된다    

![스크린샷 2024-12-10 145220](https://github.com/user-attachments/assets/d4e5389f-837e-45bc-bd87-383bfebcb47b)
- ReplicatedUsing = OnRep_Currenthp를 해당 Hp값이 변경되면 클라이언트에게 변경된 값을 동기화
- 서버에서 피격 데미지를 계산 후 -> 클라이언트 

### Net

- 전체적으로 서버에거 계산을 하고 클라이언트에게 계산된 값만 매개변수로 전달하는 형식 or ReplicatedUsing 사용한 변수 바인딩으로 해당 변수 값이 변하면 등록된 함수를 호출하게 했다
![스크린샷 2024-12-10 144354](https://github.com/user-attachments/assets/a373f9d0-3abf-4a73-8dd3-38b06ead6192)

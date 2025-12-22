"""
r-2, c-1
r-2, c+1
r+1, c+2
r-1, c+2
r+2, c-1
r+2, c+1
r+1, c-2
r-1, c-2
"""
ans_count=0
def isSafe(board, r, c):
    loc=[[-2,-1],[-2,1],[1,2],[-1,2],[2,-1],[2,1],[1,-2],[-1,-2]]

    for i in loc:
        if(r+i[0] >=0 and r+i[0]<len(board) and c+i[1]>=0 and c+i[1]<len(board)):
            if board[r+i[0]][c+i[1]]:
                return False
    
    return True

def add_ans(board):
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j]:
                print("K",end=" ")
            else:
                print(".",end=" ")
        print()


def nKnight(board,r,c,kn):
    if kn==0:
        global ans_count
        ans_count+=1
        add_ans(board)
        print()
        return
    
    if r==len(board):
        return
    
    if c==len(board):
        nKnight(board,r+1,0,kn)
        return
    
    if isSafe(board,r,c):
        board[r][c]=True
        nKnight(board,r,c+1,kn-1)
        board[r][c]=False
    
    nKnight(board,r,c+1,kn)


if __name__=="__main__":
    n=3
    board=[[False for _ in range(n)] for _ in range(n)]
    nKnight(board,0,0,n)
    print(ans_count)




    
    


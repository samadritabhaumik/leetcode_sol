class Spreadsheet {
private:
    vector<vector<int>> grid;
    int column(char col) {
        return col - 'A';
    }
    pair<int, int> indices(string cell) {
        int col = column(cell[0]);
        int row = stoi(cell.substr(1)) - 1; 
        return {row, col};
    }
public:
    Spreadsheet(int rows) {
        grid = vector<vector<int>>(rows, vector<int>(26, 0)); 
    }
    void setCell(string cell, int value) {
        auto [row, col] = indices(cell);
        grid[row][col] = value;
    }
    void resetCell(string cell) {
        auto [row, col] =indices(cell);
        grid[row][col] = 0;
    }
    int getValue(string formula) {
        formula = formula.substr(1); 
        size_t plusPos = formula.find('+');
        string first= formula.substr(0, plusPos);
        string second= formula.substr(plusPos + 1);
        auto solve= [&](string operand) -> int {
            if (isdigit(operand[0])) return stoi(operand); 
            auto [row, col] =indices(operand);
            return grid[row][col]; 
        };
        return solve(first)+solve(second);}
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
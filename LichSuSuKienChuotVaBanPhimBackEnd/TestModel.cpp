#include "TestModel.h"

using namespace std;

static SQLHENV env;
static SQLHDBC dbc;
static SQLHSTMT stmt;
SQLCHAR connStr[] =
"DRIVER={ODBC Driver 18 for SQL Server};"
"SERVER=localhost\\SQLEXPRESS;"
"DATABASE=Test;"
"Trusted_Connection=Yes;"
"TrustServerCertificate=Yes;";

// ✅ 1. Kết nối SQL Server
bool ConnectDatabase() {
    SQLRETURN ret;

    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);

    ret = SQLDriverConnectA(dbc, NULL, connStr, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);

    if (!SQL_SUCCEEDED(ret)) {
        cout << "❌ Ket noi that bai!" << endl;
        return false;
    }
    cout << "✅ Ket noi thanh cong!" << endl;

    // ✅ Chọn đúng Database
    SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
    SQLExecDirectA(stmt, (SQLCHAR*)"USE Test;", SQL_NTS);
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);

    return true;
}

// ✅ 2. Ngắt kết nối
void DisconnectDatabase() {
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
    SQLDisconnect(dbc);
    SQLFreeHandle(SQL_HANDLE_DBC, dbc);
    SQLFreeHandle(SQL_HANDLE_ENV, env);
    cout << "🔌 Da ngat ket noi!" << endl;
}

// ✅ 3. Thêm dữ liệu vào Vector2
bool InsertVector2(int a, int b) {
    SQLRETURN ret;
    SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);

    string query = "INSERT INTO dbo.Vector2 VALUES ("
        + to_string(a) + ","
        + to_string(b) + ");";

    ret = SQLExecDirectA(stmt, (SQLCHAR*)query.c_str(), SQL_NTS);

    if (SQL_SUCCEEDED(ret)) {
        cout << "✅ Them vector thanh cong: (" << a << ", " << b << ")" << endl;
        return true;
    }
    cout << "❌ Them vector that bai!" << endl;
    return false;
}

// ✅ 4. Đọc dữ liệu từ Vector2
std::vector<Vector2> SelectVector2()
{
    SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);

    vector<Vector2> danhSach;

    if (!SQL_SUCCEEDED(SQLExecDirectA(stmt, (SQLCHAR*)"SELECT a, b FROM dbo.Vector2;", SQL_NTS))) {
        cout << "❌ Select that bai!" << endl;
        return danhSach; // trả về rỗng
    }

    int a, b;

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLGetData(stmt, 1, SQL_C_SLONG, &a, 0, NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &b, 0, NULL);

        Vector2 v;
        v.a = a;
        v.b = b;

        danhSach.push_back(v);
    }

    return danhSach;
}

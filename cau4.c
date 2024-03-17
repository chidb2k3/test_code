#include <stdio.h>
#include <stdbool.h>

// Hàm nhập giá trị cho mảng
void nhapMang(int arr[], int n) {
    printf("Nhap gia tri cho cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Hàm xem mảng
void xemMang(int arr[], int n) {
    printf("Cac phan tu cua mang la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm xóa phần tử có giá trị x trên mảng
void xoaPhanTu(int arr[], int *n, int x) {
    int i, j;
    for (i = 0; i < *n; i++) {
        if (arr[i] == x) {
            for (j = i; j < *n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*n)--;
            i--;
        }
    }
}

// Hàm kiểm tra xem một số có phải là số nguyên tố hay không
bool laSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm đếm số lượng số nguyên tố trong mảng
int demSoNguyenTo(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) {
            count++;
        }
    }
    return count;
}

// Hàm chèn giá trị x vào vị trí k
void chenPhanTu(int arr[], int *n, int k, int x) {
    (*n)++;
    for (int i = *n - 1; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
}

// Hàm tìm vị trí đầu tiên của phần tử có giá trị x
int timPhanTu(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -2; // Trả về -2 nếu không tìm thấy
}

// Hàm đếm số lượng số có 2 chữ số trong mảng
int demSoHaiChuSo(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 10 && arr[i] <= 99) {
            count++;
        }
    }
    return count;
}

// Hàm hiển thị menu và thực thi các chức năng
void menu(int arr[], int *n) {
    int choice;
    int x, k;

    do {
        printf("\n-- Menu --\n");
        printf("1. Xem mang\n");
        printf("2. Xoa phan tu\n");
        printf("3. Dem so nguyen to\n");
        printf("4. Chen phan tu\n");
        printf("5. Tim phan tu dau tien\n");
        printf("6. Dem so co 2 chu so\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                xemMang(arr, *n);
                break;
            case 2:
                printf("Nhap gia tri can xoa: ");
                scanf("%d", &x);
                xoaPhanTu(arr, n, x);
                break;
            case 3:
                printf("So luong so nguyen to: %d\n", demSoNguyenTo(arr, *n));
                break;
            case 4:
                printf("Nhap gia tri can chen: ");
                scanf("%d", &x);
                printf("Nhap vi tri can chen: ");
                scanf("%d", &k);
                chenPhanTu(arr, n, k, x);
                break;
            case 5:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                printf("Vi tri dau tien cua %d: %d\n", x, timPhanTu(arr, *n, x));
                break;
            case 6:
                printf("So luong so co 2 chu so: %d\n", demSoHaiChuSo(arr, *n));
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 0);
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];

    nhapMang(arr, n);

    menu(arr, &n);

    return 0;
}

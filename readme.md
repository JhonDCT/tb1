### 🧩 Caso de uso: Listar usuarios y mostrar detalle

**Flujo general:**
- `UserListContainer` (Smart) → obtiene lista de usuarios.
- `UserTableComponent` (Dumb) ← recibe `@Input users`.
- El usuario hace click → `@Output selectUser(User)` emitido.
- `UserListContainer` llama `GetUserDetailUseCase` → actualiza `UserDetailComponent`.

```mermaid
flowchart LR
  A[UserListContainer] -->|@Input users| B[UserTableComponent]
  B -->|@Output selectUser| A
  A -->|@Input user| C[UserDetailComponent]

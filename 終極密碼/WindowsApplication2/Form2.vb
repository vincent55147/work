Public Class Form2
    Dim password As Integer
    Private Sub TextBox1_TextChanged(sender As Object, e As EventArgs) Handles TextBox1.TextChanged

    End Sub

    Private Sub Form2_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        TextBox1.PasswordChar = "*"
        password = 88147
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        If TextBox1.Text = 88147 Then
            Shell("shutdown -a")
            Application.Exit()
        Else
            Label2.Text = "在試一次吧"
        End If
    End Sub
End Class
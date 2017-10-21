Public Class form1
    Private Sub btnreset_Click(sender As Object, e As EventArgs) Handles btnreset.Click
        form1_Load(sender, e)
        txtsmall.Enabled = True
        txtlarge.Enabled = True
        done.Enabled = True
        txtguess.Text = ""
        txtlarge.Focus()
    End Sub
    Dim ansn, guessn, smalln, largen As Integer
    Public x As Integer
    Private Sub done1()
        Try
            largen = txtlarge.Text
            smalln = txtsmall.Text
        Catch ex As Exception
            txttop.Text = "請輸入數字"
            txtlarge.Text = ""
            Return
        End Try
        If txtlarge.Text - txtsmall.Text >= 100 Then
            getstart()
            Dim rnd As New Random()
            ansn = rnd.Next(txtsmall.Text, txtlarge.Text)
            txtsmall.Enabled = False
            txtlarge.Enabled = False
            btnok.Enabled = True
            done.Enabled = False
            txtguess.Enabled = True
            btnreset.Enabled = True
        Else
            txttop.Text = "大小值差超過100"
        End If
        txtguess.Focus()
    End Sub
    Private Sub getstart()
        txtguess.Text = ""
        txtguess.Focus()
    End Sub
    Private Sub ok()
        Try
            guessn = txtguess.Text
        Catch ex As Exception
            txttop.Text = "請輸入數字"
            Return
        End Try
        If (guessn = ansn) Then
            MessageBox.Show("恭喜中獎", "提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk)
        Else
            If (guessn > txtlarge.Text Or guessn < txtsmall.Text Or guessn = txtlarge.Text Or guessn = txtsmall.Text) Then
                MessageBox.Show("你再亂嗎", "警告", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
            ElseIf (guessn < ansn) Then
                If (guessn - txtsmall.Text = 1) Then
                    txttop.Text = "膽小鬼"
                    txtsmall.Text = guessn
                Else
                    txtsmall.Text = guessn
                    txttop.Text = "大一點就中獎"
                End If

            ElseIf (guessn > ansn) Then
                If (txtlarge.Text - guessn = 1) Then
                    txttop.Text = "膽小鬼"
                    txtlarge.Text = guessn
                Else
                    txtlarge.Text = guessn
                    txttop.Text = "小一點就中獎"
                End If
            End If
            getstart()
        End If
    End Sub
    Private Sub form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        txtlarge.Text = ""
        txtlarge.Focus()
        txttop.Text = "請在左右方輸入最大與最小值"
        ToolTip1.SetToolTip(txtguess, "請輸入數字")
        ToolTip1.SetToolTip(txtsmall, "請輸入數字")
        ToolTip1.SetToolTip(txtlarge, "請輸入數字")
        btnok.Enabled = False
        txtguess.Enabled = False
        btnreset.Enabled = False
        txtsmall.Text = 0
    End Sub
    Private Sub btnok_Click(sender As Object, e As EventArgs) Handles btnok.Click
        ok()
    End Sub
    Private Sub btnexit_Click(sender As Object, e As EventArgs) Handles btnexit.Click
        Application.Exit()
    End Sub
    Private Sub done_Click(sender As Object, e As EventArgs) Handles done.Click, done.Enter
        done1()
    End Sub
    Private Sub txtlarge_TextChanged(sender As Object, e As EventArgs) Handles txtlarge.TextChanged

    End Sub
    Private Sub txtlarge_Enter(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyPressEventArgs) Handles txtlarge.KeyPress
        If e.KeyChar = Chr(13) Then
            done1()
        End If
    End Sub
    Private Sub txtguess_KeyPress(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyPressEventArgs) Handles txtguess.KeyPress
        If e.KeyChar = Chr(13) Then
            ok()
        End If
    End Sub
    Private Sub txtsmall_TextChanged(sender As Object, e As EventArgs) Handles txtsmall.TextChanged

    End Sub
End Class
